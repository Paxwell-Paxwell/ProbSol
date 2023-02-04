#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, P, V, i;
    cin >> n;
    int price[n], eff[n];
    set<int, greater<int> > vv;
    int count = 0;

    //get data
    for (i=0;i<n;i++) {
        cin >> P >> V;
        price[i] = P;
        eff[i] = V;
        vv.insert(V);
    }

    for (i=0;i<n;i++) {
        int tmp = eff[i], x = *vv.begin();
        if (tmp < x) count++;
        vv.erase(tmp);
    }

    cout << count << "\n";
}