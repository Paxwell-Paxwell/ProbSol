#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int n, s;
vector<int> seq;
vector<int> smax;
vector<int> aseq[MAX_N];

int nans;
vector<int> vans;

void get_input() {
    cin >> n;
    seq.resize(n);
    smax.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
} 

void find_max(int index) {
    int max = 1;
    vector<int> ans = {seq[index]};
    for (int i = 0; i < index; i++) {
        if (seq[i] < seq[index] && smax[i] + 1 >= max) {
            max = smax[i] + 1;
            ans = aseq[i];
            ans.push_back(seq[index]);
        }
    }
    smax[index] = max;
    aseq[index] = ans;
    if (max >= nans) {
        nans = max;
        vans = ans;
    }

}

void solve() {
    for (int i = 0; i < n; i++) {
        find_max(i);
    }
    cout << nans << "\n";
    for (int i = 0; i < vans.size(); i++) {
        cout << vans[i] << " ";
    }
    cout << "\n";
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < aseq[i].size(); j++) {
            cout << aseq[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    get_input();
    solve();
    //debug();
    return 0;
}