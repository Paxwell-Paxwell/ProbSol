// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int n, k, i, j, x = 0, y = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string command = "";
    cin >> command;
    for (i=0;i<100;i++) {
        if (command[i] == '\0') break;
        else if (command[i] == 'N') y += 1;
        else if (command[i] == 'S') y -= 1;
        else if (command[i] == 'E') x += 1;
        else if (command[i] == 'W') x -= 1;
        else if (command[i] == 'Z') {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y << "\n";
    return 0;
}