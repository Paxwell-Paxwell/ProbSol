#include <bits/stdc++.h>
using namespace std;

#define MAX 201

string s,t;

int memos[MAX][MAX];
string str[MAX][MAX];

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
                str[i][j] = "";
            } else if (s[i - 1] == t[j - 1]) {
                memos[i][j] = memos[i - 1][j - 1] + 1;
                str[i][j] = str[i - 1][j - 1] + s[i - 1];
            } else {
                if (memos[i - 1][j] > memos[i][j - 1]) {
                    memos[i][j] = memos[i - 1][j];
                    str[i][j] = str[i - 1][j];
                } else {
                    memos[i][j] = memos[i][j - 1];
                    str[i][j] = str[i][j - 1];
                }
                //memos[i][j] = max(memos[i - 1][j], memos[i][j - 1]);
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

void debug2() {
    cout << "Debug: \n";
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            if (i != j || memos[i][j] == memos[i + 1][j + 1])
                continue;
            cout << s[i] << " ";
        }
        cout << "\n";
    }
}

void printLCS() {
    cout << str[s.size()][t.size()] << "\n";
}

int main() {
    input();
    LCS();
    //debug2();
    cout << memos[s.size()][t.size()] << "\n";
    printLCS();
    return 0;
}