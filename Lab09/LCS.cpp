#include <bits/stdc++.h>
using namespace std;

#define MAX 201

string s,t;

int memos[MAX][MAX];

void input(){
    cin >> s >> t;
}

void LCS() {
    int n = s.size();
    int m = t.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                memos[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                memos[i][j] = memos[i - 1][j - 1] + 1;
            } else {
                memos[i][j] = max(memos[i - 1][j], memos[i][j - 1]);
            }
        }
    }
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

int main() {
    input();
    LCS();
    cout << memos[s.size()][t.size()] << "\n";
    return 0;
}