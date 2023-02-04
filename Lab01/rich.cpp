// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int n, i;
    int m;
    int money = 0;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> m;
        if (m >= 0) { 
            money += m;
        }
    }
    cout << money << "\n";
    return 0;
}