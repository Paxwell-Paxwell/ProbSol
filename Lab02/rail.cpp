#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, value, tmp;
    int possible;
    string X;
    //For each box
    while (1) {
        cin >> n;
        if (n == 0) break;
        //for each order
        while (1) {
            possible = 1;
            if (n == 0) break;
            //create stack
            stack<int> station;
            stack<int> A;
            //cout << station.empty() << A.empty() << "\n";
            for (i=n;i>0;i--) A.push(i);
            for (i=0;i<n;i++) {
                cin >> value;
                if (value == 0) {
                    cout << "\n";
                    break;
                    }
                if (!possible) continue;
                //case1: train still in A
                while (!A.empty() && value >= A.top()) {
                    //cout << "value " << value << "\n";
                    tmp = A.top();
                    station.push(tmp);
                    A.pop();
                    //cout << "Stack station push " << tmp << "\n";
                }
                //cout << "Stack station top " << station.top() << "\n";
                if (value == station.top()) {
                    station.pop();
                    //cout << "Stack station pop " << value << "\n";
                }
                else {
                    possible = 0;
                }
            }
            while (!A.empty()) A.pop();
            while (!station.empty()) station.pop();
            
            if (value != 0) cout << (possible ? "Yes\n" : "No\n");
            else break;
        }
    }

    return 0;
}