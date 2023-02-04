#include <bits/stdc++.h>
using namespace std;

int h, w;

vector<vector<char> > Map;

void get_input() {
    cin >> h >> w;
    char x;
    for (int i=0;i<h;i++) {
        vector<char> X;
        for (int j=0;j<w;j++) {
            cin >> x;
            X.push_back(x);
        }
        Map.push_back(X);
    }
}

