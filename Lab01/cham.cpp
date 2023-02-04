// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int n, i;
    int m;
    int max = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int storage[301];
    memset(storage, 0, sizeof(storage));
    for (i=0; i<n; i++) {
        cin >> m;
        storage[m] += 1;
    }
    for (i=1; i<=300; i++) {
        if (max < storage[i]) {
            max = storage[i];
        }
    } 
    cout << max << "\n";
    return 0;
}