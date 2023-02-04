// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int n, i;
    int c;
    int max = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int sendto[n+1];
    int used[n+1];
    int current;
    for (i=1;i<=n;i++) {
        cin >> sendto[i];
        used[i] = 0;
    }
    for (i=1;i<=n;i++) {
        c = 1;
        current = sendto[i];
        if (used[i]) continue;
        while (current != i) {
            //cout << current << " " << sendto[i] << " " << c << "\n";
            current = sendto[current];
            used[current] = 1;
            c++;
        }
        if (max < c) {
            max = c;
        }
    }

    cout << max << "\n";
    return 0;
}