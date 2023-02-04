#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> skill;
vector<int> position;

void get_input() {
    cin >> n;
    int max = -1;
    int posi;
    for (int i=0;i<4*n;i++) {
        int x;
        cin >> x;
        if (x > max) {
            max = x;
            posi = i + 1;
            }
        if ((i+1)%n == 0) {
            skill.push_back(max);
            position.push_back(posi);
            max = -1;
        }
    }
}

void find_winner() {
    int one, two, A, B;
    int temp1,temp2;
    if (skill[0] > skill[1]) {
        temp1 = 0;
        A = 1;
    }
    else {
        temp1 = 1;
        A = 0;
    }
    if (skill[2] > skill[3]) {
        temp2 = 2;
        B = 3;
    }
    else {
        temp2 = 3;
        B = 2;
    }
    if (skill[temp1] > skill[temp2]) {
        one = temp1;
        two = temp2;
    }
    else {
        one = temp2;
        two = temp1;
    }
    cout << position[one] << " " << position[two] << " " << position[A] << " " << position[B] << "\n";
}

int main() {
    get_input();
    find_winner();

}