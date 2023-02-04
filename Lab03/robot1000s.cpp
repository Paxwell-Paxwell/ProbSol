#include <bits/stdc++.h>
using namespace std;

string command;
int NESW[4] = {0};
int csize;
int loss;

void get_input() {
    cin >> command;
    cin >> loss;
    csize = command.size();
}

void set_NESW() {
    int x = 0, y = 0, mx, my;
    int max = -1;
    for (int i=0;i<csize;i++) {
        if (command[i] == 'N') NESW[0]++;
        if (command[i] == 'E') NESW[1]++;
        if (command[i] == 'S') NESW[2]++;
        if (command[i] == 'W') NESW[3]++;
    }
}

void del_one() {
    int index = 0;
    int min = 9999;
    for (int i=0;i<4;i++) {
        if (NESW[i] < min && NESW[i] > 0) {
            min = NESW[i];
            index = i;
        }
    }
    NESW[index]--;
}

void del_loss() {
    for (int i=0;i<loss;i++) {
        del_one();
    }
}

void fuel() {
    int x = abs(NESW[1] - NESW[3]);
    int y = abs(NESW[0] - NESW[2]);
    cout << (x * 2 + y * 2) << "\n";
}


int main() {
    get_input();
    set_NESW();
    del_loss();
    fuel();
    return 0;
}