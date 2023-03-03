#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int c, n, k;

void debug(vector<vector<int>> &dp) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2 * k + 1; j++) {
            if (dp[i][j] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << " " << dp[i][j] << "  ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> c;
    for (int ix = 0; ix < c; ix++) {
        cin >> n >> k;
        vector<int> a(n + 1), b(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, INT_MAX));
        dp[0][k] = 0;
        //debug(dp);
        for (int j = 1; j <= n; j++) {
            cin >> a[j] >> b[j];
        }
        a.push_back(0);
        b.push_back(0);
        cout << "\n";
        //recurrence relation : dp[i][k] = min(a[i] + dp[i-1][k+1], b[i] + dp[i-1][k-1])
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2 * k + 1; j++) {
                if (j < 2 * k && j > 0) {
                    //cout << "caseA" << "\n";
                    int temp1 = dp[i - 1][j + 1] == INT_MAX ? INT_MAX : a[i] + dp[i - 1][j + 1];
                    int temp2 = dp[i - 1][j - 1] == INT_MAX ? INT_MAX : b[i] + dp[i - 1][j - 1];
                    dp[i][j] = min(temp1, temp2);
                }
                else if (j == 0) {
                    //cout << "caseB" << "\n";
                    dp[i][j] = dp[i - 1][j + 1] == INT_MAX ? INT_MAX : a[i] + dp[i - 1][j + 1];
                    //cout << "a[i]: " << a[i] << " dp[i-1][j+1]: " << dp[i - 1][j + 1] << "\n";
                }
                else if (j == 2 * k) {
                    //cout << "caseC" << "\n";
                    dp[i][j] = dp[i - 1][j - 1] == INT_MAX ? INT_MAX : b[i] + dp[i - 1][j - 1];
                }
                //cout << "i: " << i << " j: " << j << " dp[i][j]: " << dp[i][j] << "\n";
            }
        }
        debug(dp);
        int min = INT_MAX;
        for (int num : dp[n]) {
            if (num < min)
                min = num;
        }
        cout << min << "\n";
    }
    return 0;
}