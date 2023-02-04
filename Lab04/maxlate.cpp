#include<bits/stdc++.h>
using namespace std;

int n;
int max;
vector<pair<int, int> > all;

void sort_vector_pair() {
    sort(all.begin(), all.end());
}

void get_input() {
    cin >> n;
    int d, c;
    for (int i=0;i<n;i++) {
        cin >> d >> c;
        all.push_back(make_pair(d, c));
    }
}

void find_max() {
    int day = 0, max = 0;
    for (int i=0;i<n;i++) {
        day += all[i].second;
        int delay = day - all[i].first - 10;
        if (delay > 0 && 1000*delay > max) {
            max = 1000*delay;
        }
    }
    cout << max << "\n";
} 


int main() {
    get_input();
    sort_vector_pair();

    find_max();
    return 0;
}
