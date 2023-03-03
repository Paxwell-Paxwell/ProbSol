#include <bits/stdc++.h>
using namespace std;

#define MAX_N 3050

struct point {
    int num;
    int position;
};

struct compareP {
    bool operator()(point const& p1, point const& p2) {
        return p1.position > p2.position;
    }
};

int n;
int x;
priority_queue<point, vector<point>, compareP> points;
int Nposi[MAX_N];
int Sposi[MAX_N];

void get_input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x; x--;
        Nposi[x] = i;
    }
    for (int i=0;i<n;i++) {
        cin >> x; x--;
        Sposi[x] = i; 
        point tmp;
        tmp.num = x;
        tmp.position = Sposi[x];
        points.push(tmp);
    }
}

void solve() {
    int north = -1, south = -1;
    int count = 0;
    int no, so, ndis, sdis;
    while (!points.empty()) {
        point tmp = points.top();
        points.pop();
        int x = tmp.num;
        if (Nposi[x] > north && Sposi[x] > south) {
            north = Nposi[x];
            south = Sposi[x];
            count++;
        } 
    }
    cout << count << "\n";
}

int main() {
    get_input();
    solve();
    
    return 0;
}