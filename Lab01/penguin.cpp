#include <iostream>
using namespace std;

int main() {
    int n, k = 0, i, j;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int penguin[n];
    for(i=0;i<n;i++) {
        cin >> penguin[i];
    }
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if (penguin[i]<penguin[j]) k++;
        }
    }
    cout << k << "\n";
    return 0;
}