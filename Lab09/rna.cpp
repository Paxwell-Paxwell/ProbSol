#include <bits/stdc++.h>
using namespace std;

#define MAX 500

string s;

int memos[MAX][MAX];

void input() {
    cin >> s;
    memset(memos, -1, sizeof(memos));
}

int ma(int start, int end) {
    int n = end - start, mx = INT_MIN;
    if (n < 6) return 0;
    if (memos[start][end] != -1) return memos[start][end];
    for (int i = start; i < end - 5; i++) {
        if ((s[i] == 'A' && s[end - 1] == 'U') || (s[i] == 'U' && s[end - 1] == 'A') || (s[i] == 'C' && s[end - 1] == 'G') || (s[i] == 'G' && s[end - 1] == 'C')) {
            mx = max(mx, 1 + ma(start, i) + ma(i + 1, end - 1));     
        }
    }
    mx = max(mx, ma(start, end - 1));
    memos[start][end] = mx;
    //cout << s.substr(start, end - start + 1) << " " << mx << "\n";
    return mx;
}

int main() {
    input();
    cout << ma(0, s.size()) << "\n";
    return 0;
}