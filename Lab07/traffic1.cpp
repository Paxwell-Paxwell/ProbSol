#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a, b, c, d;
int t1, t2;

int search_horizontal() {
    for (int i = 0; i < n; i++) {
        if (traffic_query(1, i + 1, n, i + 1) != n - 1) {
            return i + 1;
        }
    }
    return -1;
}

int search_vertical() {
    for (int i = 0; i < n; i++) {
        if (traffic_query(i + 1, 1, i + 1, n) != n - 1) {
            return i + 1;
        }
    }
    return -1;
}

void binary_search() {
    t1 = search_vertical();
    t2 = search_horizontal();
    int l = 1, r = n;
    if (t1 != -1) {
        while (l < r) {
            int mid = (l + r) / 2;
            int x = traffic_query(t1, l, t1, mid);
            if (mid - l == 1 && x == 2) {
                traffic_report(t1, l, t1, mid, 0, 0, 0, 0);
                return;
            } else if (r - mid == 1 && traffic_query(t1, mid, t1, r) == 2) {
                traffic_report(t1, mid, t1, r, 0, 0, 0, 0);
                return;
            }
            if (x == mid - l) {
                l = mid;
            } else {
                r = mid;
            }
        }
    } else {
        while (l < r) {
            int mid = (l + r) / 2;
            int x = traffic_query(l, t2, mid, t2);
            if (mid - l == 1 && x == 2) {
                traffic_report(l, t2, mid, t2, 0, 0, 0, 0);
                return;
            } else if (r - mid == 1 && traffic_query(mid, t2, r, t2) == 2) {
                traffic_report(mid, t2, r, t2, 0, 0, 0, 0);
                return;
            }
            if (x == mid - l) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }
}

int main() {
    traffic_init(&n, &k);
    binary_search();
}
