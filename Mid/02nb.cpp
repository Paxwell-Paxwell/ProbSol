#include<bits/stdc++.h>
using namespace std;

int n;
long long int h;
vector<long long int> height;
vector<long long int> dp;

void get_input() {
    cin >> n;
    dp.resize(n, INT_MAX);
    for (int i=0;i<n;i++) {
        cin >> h;
        height.push_back(h);
    }
}

void solve() {
    dp[0] = 0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            long long int tmp1 = (height[j] > height[i] ? (height[j] - height[i]) : (height[i] - height[j]));
            dp[j] = min(dp[j], dp[i] + tmp1);
        }
    }
    cout << dp[n-1] << "\n";
}

int main() {
    get_input();
    solve();
    return 0;
}
