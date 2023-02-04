#include<bits/stdc++.h>
using namespace std;

#define MAX_N 200010

int n, tmp1, mx = -1, gr;
int go_right[MAX_N];

void get_input() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> tmp1;
        gr = (tmp1 - (i + 1) > 0 ? tmp1 - (i + 1) : tmp1 + n - (i + 1));
        go_right[gr]++;
        if (go_right[gr] > mx) {
            mx = go_right[gr];
        }
    }
    cout << mx << "\n";
}

int main() {
    get_input();
    return 0;
}