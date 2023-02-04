// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int n, i;
    int x, y;
    int score = 0;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> x >> y;
        if (x*x + y*y > 100) {
            score += 0;
        }
        else if (x*x + y*y > 64) {
            score += 1;
        }
        else if (x*x + y*y > 36) {
            score += 2;
        }
        else if (x*x + y*y > 16) {
            score += 3;
        }
        else if (x*x + y*y > 4) {
            score += 4;
        }
        else {
            score += 5;
        }
    }
    cout << score << "\n";
    return 0;
}