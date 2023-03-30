#include <bits/stdc++.h>
using namespace std;

#define MAX 400

string s,t;
int memos[MAX][MAX];

//recurrence relation
//dp[i,j] = min(dp[i-1,j]+1, 
//              dp[i,j-1]+1, 
//              dp[i-1,j-1]+1, 
//              dp[i-1,j-1] if s[i] == t[j])

void input(){
    cin >> s >> t;
}

void debug() {
    cout << "Debug: \n";
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            cout << memos[i][j] << " ";
        }
        cout << "\n";
    }
}

void LCS() {
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                memos[i][j] = max(i, j);
                continue;
            }
            int case1 = memos[i - 1][j] + 1;
            int case2 = memos[i][j - 1] + 1;
            int case3 = memos[i - 1][j - 1] + 1;
            int case4 = (s[i - 1] == t[j - 1]) ? memos[i - 1][j - 1] : INT_MAX;
            memos[i][j] = min(case1, min(case2, min(case3, case4)));
        }
    }
    cout << memos[n][m] << "\n";
}

int main() {
    input();
    LCS();
    return 0;
}