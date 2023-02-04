#include<bits/stdc++.h>
using namespace std;

int n;
long long int h;
vector<long long int> height;

void get_input() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> h;
        height.push_back(h);
    }
}

long long int sum(int b, int c) {
    //copy index b to c;
    long long int s = 0;
    vector<long long int> tmp = height;
    tmp[c] = tmp[b];
    for (int i=0;i<n-1;i++) {
        long long int tmp1 = (tmp[i+1] > tmp[i] ? (tmp[i+1] - tmp[i]) : (tmp[i] - tmp[i+1]));
        s += tmp1;
    }
    return s;
}

//brute forceeeee

void solve() {
    int min = INT_MAX;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<i-1;j++) {
            if (height[j] < 2*height[i] || 2*height[j] < height[i]) continue;
            int tmp = sum(i,j);
            if (tmp < min) {
                min = tmp;
            }
        }
        for (int j=i+2;j<n;j++) {
            int tmp = sum(i,j);
            if (tmp < min) {
                min = tmp;
            }
        }
    }
    cout << min << "\n";
}

int main() {
    get_input();
    solve();
    return 0;
}