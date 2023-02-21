#include "probelib.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX_PROBE 22
#define MAX_N 100000

int n, target;

int binary_search(int s, int e) {
    int mid = (s + e) / 2;
    if (probe_check(s, mid)) {
        if (s == e) {
            return s;
        }
        else {
            return binary_search(s, mid);
        }
    }
    else {
        return binary_search(mid + 1, e);
    }
}

int main() {
    n = probe_init();
    int answer = binary_search(0, n - 1);
    probe_answer(answer);
    return 0;
}