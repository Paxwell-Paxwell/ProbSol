#include <bits/stdc++.h>
using namespace std;

string command;
char tid[4] = {'N', 'E', 'S', 'W'};
int direct = 0;

void get_input() {
    cin >> command;
}

void rosetta() {
    string newcommand;
    for (int i=0;i<command.size();i++) {
        if (command[i] == 'Z') {
            direct = 0;
            newcommand += 'Z';
            continue;
        }
        while (tid[direct] != command[i]) {
            direct++;
            direct%=4;
            newcommand += 'R';
        }
        if (tid[direct] == command[i]) {
            newcommand += 'F';
        }
    }
    cout << newcommand << "\n";
}

int main() {
    get_input();
    rosetta();
}