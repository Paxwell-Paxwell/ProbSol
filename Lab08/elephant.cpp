#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> seq;
vector<int> smax;

void input() {
    cin >> n;
    seq.resize(n);
    smax.resize(n);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
}

void base_max() {
    smax[0] = 0;
    smax[1] = 0;
    smax[2] = seq[2];
}

void find_max(int index) {
    int max1 = seq[index] + smax[index - 3]; 
    smax[index] = max(max1, max(smax[index - 1], smax[index - 2]));
}

void solve() {
    base_max();
    for (int i = 3; i < n; i++) {
        find_max(i);
    }
    cout << smax[n - 1] << "\n";
}

void debug() {
    for (int i = 0; i < n; i++) {
        cout << seq[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << smax[i] << " ";
    }
    cout << "\n";
}

int main() {
    input();
    base_max();
    solve();
    debug();
    return 0;
}