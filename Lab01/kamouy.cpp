// Your First C++ Program
#include <iostream>
using namespace std;

int main() {
    int N, K, T;
    int count = 1, at = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> T;
    //cout << at << count << "a\n";
    at += K;
    while (at != 1) {
        //cout << at << count << "a\n";
        at += K;
        count++;
        if (at > N) at -= N;
        if (at == T) {
            count++;
            break;
            }
    }
    cout << count << "\n";
    return 0;
}