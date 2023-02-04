#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, i, j;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    long long int period[n];
    int notsur[n];
    long long int min = 0; 
    for (i=0;i<n;i++) {
        notsur[i] = 0;
        cin >> period[i];
        if (i == 0) min = period[i];
        else if (min > period[i]) min = period[i];
    }
    int survival = n;
    for (j=0;j<n;j++) {
        if (notsur[j]) continue;
        if (min*k <= period[j]*(k-1)) {
            notsur[j] = 1;
            survival--;
        }
    }
    cout << survival << "\n";
    return 0;
}