#include <iostream>
using namespace std;

void step1(int n, int data[]) {
    int i;
    int N = n;
    for (i=0;i<n;i++) {
        if (i == 0) {
            if (data[i] == N-1) cout << 0 << "\n";
            else if (data[i] == N+1) cout << 1 << "\n";
        }
        else {
            if (data[i] > data[i-1]) cout << 1 << "\n";
            if (data[i] < data[i-1]) cout << 0 << "\n";
        }
    }
}

void step2(int n, int data[]) {
    int i;
    int N = n;
    int ans[n];
    for (i=0;i<n;i++) {
        if (i == 0) {
            ans[i] = data[i];
        }
        else {
            if (data[i]-3*ans[i-1] == 1) {
                ans[i] = ans[i-1] + 1;
            }
            else if (2*ans[i-1]-data[i] == 1) {
                ans[i] = ans[i-1] - 1;
            }
        }
    }
    step1(n, ans);
}

int main() {
    int n, t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    int data[n];
    for (i=0;i<n;i++) {
        cin >> data[i];
    }
    int N = n;
    if (t == 1) {
        step1(n, data);
    }
    else if (t == 2) {
        step2(n, data);
    }
    return 0;
}