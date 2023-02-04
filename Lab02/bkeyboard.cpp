#include <bits/stdc++.h>
using namespace std;

int main() {
    //case 0: normal, case 1: home
    int i, cse;
    char c;
    string x, tmp, newS;
    while (getline(cin , x)) {
        stack<string> front;
        tmp = "", newS = "";
        cse = 0;
        for (i=0;i<x.length();i++) {
            if (x[i] == '[') {
                cse = 1;
                if (tmp != "") {
                    front.push(tmp);
                    tmp = "";
                    }
                }
            else if (x[i] == ']') {
                cse = 0;
                if (tmp != "") {
                    front.push(tmp);
                    tmp = "";
                    }
                }
            else {
                if (!cse) {
                    newS += x[i];
                }
                else {
                    tmp += x[i];
                }
            }
        }
        if (tmp != "") front.push(tmp);
        tmp = "";
        while (!front.empty()) {
            tmp += front.top();
            front.pop();
        }
        newS = tmp + newS;
        cout << newS << "\n";
    }
    return 0;
}