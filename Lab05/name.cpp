#include<bits/stdc++.h>
using namespace std;

string S, T;

void get_input() {
    cin >> S;
    cin >> T;
}

void check() {
    int count = 0, at = 0, size = S.size();
    for (auto c : T) {
        if (c == S[at]) {
            at++;
        }
        if (at == size) {
            count++;
            at = at % size;
        }
    }
    cout << count << "\n";
}

int main() {
    get_input();
    check();
    return 0;
}