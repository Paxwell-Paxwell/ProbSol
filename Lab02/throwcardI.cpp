#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, tmp;
    queue<int> x;
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (i=1;i<=n;i++) x.push(i);
        
        while (x.size() != 1) {
            //Throw away first card
            tmp = x.front();
            x.pop();
            if (x.size() > 1) cout << " " << tmp << ",";
            else if (x.size() == 1)cout << " " << tmp;
            //Put top to bottom
            tmp = x.front();
            x.pop();
            x.push(tmp);
        }
        cout << "\nRemaining card: " << x.front() << "\n";
        x.pop();
    }

    return 0;
}