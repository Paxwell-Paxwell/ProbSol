#include <bits/stdc++.h>
using namespace std;

#define MAX_BRIDGE 200

int l, n;
int *bridge;



void get_input() {
    cin >> l >> n;

    int max = -1;
    int brid[2*l+1];
    fill_n(brid, 2*l+1, 0);
    bridge = brid;

    int sta, end;
    for (int i=0;i<n;i++) {
        cin >> sta >> end;
        for (int j=2*sta+1;j<2*end;j++) {
            brid[j]++;
            if (brid[j] > max) {
                max = brid[j];
            }
        }
    }
    cout << max << "\n";
}



int main() {
    get_input();
    return 0;
}