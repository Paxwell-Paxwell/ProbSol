#include <bits/stdc++.h>
using namespace std;

bool is_in(set<int> s, int key) {
    if (s.find(key) != s.end()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n, i, j, s, count = 0;
    cin >> n;
    set<int> sum;
    int arr[n];
    for (i=0;i<n;i++) cin >> arr[i];
    for (i=0;i<n;i++) {
        s = arr[i];
        if (!is_in(sum, s)) {
            sum.insert(s);
            count ++;
            }
        for (j=i+1;j<n;j++) {
            s += arr[j];
            if (!is_in(sum, s)) {
                sum.insert(s);
                count ++;
            }
        }
    }
    cout << count << endl;
}