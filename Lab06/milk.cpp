#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, q;

char v;
int x, y;

int parent[MAXN];
int Size[MAXN];

int find(int x) {
    if (parent[x] == -1) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (Size[x] > Size[y]) {
            parent[y] = x;
            Size[x] += Size[y];
        }
        else {
            parent[x] = y;
            Size[y] += Size[x];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        Size[i] = 1;
    }
    for (int i = 0; i < q; i++) {
        cin >> v >> x >> y; x--; y--;
        if (v == 'c') {
            Union(x, y);
        }
        else if (v == 'q') {
            x = find(x);
            y = find(y);
            if (x == y) {
                cout << "yes" << "\n";
            }
            else {
                cout << "no" << "\n";
            }
        }
    }
    return 0;
}