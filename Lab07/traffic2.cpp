#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a, b, c, d;

vector<int> ans;
list<int> vt1;
list<int> vt2;
int t1, t2;

void search_horizontal() {
    for (int i = 0; i < n; i++) {
        if (traffic_query(1, i + 1, n, i + 1) != n - 1) {
            vt2.push_back(i + 1);
        }
    }
}

void search_vertical() {
    for (int i = 0; i < n; i++) {
        if (traffic_query(i + 1, 1, i + 1, n) != n - 1) {
            vt1.push_back(i + 1);
        }
    }
}



void binary_search() {
    search_vertical();
    search_horizontal();
    int l = 1, r = n;
    while (!vt1.empty()) {
        t1 = vt1.front();
        vt1.pop_front();
        while (l < r) {
            int mid = (l + r) / 2;
            int x = traffic_query(t1, l, t1, mid);
            if (mid - l == 1 && x == 2) {
                ans.push_back(t1);
                ans.push_back(l);
                ans.push_back(t1);
                ans.push_back(mid);
            }
            else if (r - mid == 1 && traffic_query(t1, mid, t1, r) == 2) {
                ans.push_back(t1);
                ans.push_back(mid);
                ans.push_back(t1);
                ans.push_back(r);
            }
            if (ans.size() == 8)
                return;
            if (x == mid - l) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
    }
    while (!vt2.empty()) {
        t2 = vt2.front();
        vt2.pop_front();
        while (l < r) {
            int mid = (l + r) / 2;
            int x = traffic_query(l, t2, mid, t2);
            if (mid - l == 1 && x == 2) {
                ans.push_back(l);
                ans.push_back(t2);
                ans.push_back(mid);
                ans.push_back(t2);
            }
            else if (r - mid == 1 && traffic_query(mid, t2, r, t2) == 2) {
                ans.push_back(mid);
                ans.push_back(t2);
                ans.push_back(r);
                ans.push_back(t2);
            }
            if (ans.size() == 8)
                return;
            if (x == mid - l) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
    }
}

void report() {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    if (ans.size() == 4) {
        traffic_report(ans[0], ans[1], ans[2], ans[3], 0, 0, 0, 0);
    }
    else if (ans.size() == 8) {
        traffic_report(ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7]);
    }
}

int main() {
    traffic_init(&n, &k);
    binary_search();
    report();
}
