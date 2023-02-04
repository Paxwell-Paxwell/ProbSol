#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > all;
int now = 1;

bool sortsec(const pair<int, int> &a,const pair<int, int> &b) {
    return (a.second < b.second);
}

void sort_vector_pair() {
    sort(all.begin(), all.end(), sortsec);
}

void get_input() {
    cin >> n;
    int s, e;
    for (int i=0;i<n;i++) {
        cin >> s >> e;
        all.push_back(make_pair(s, e));
    }
    //cout << all.size() << "\n";
}

void count() {
    int count = 1;
    int now = all[0].second;
    for (int i=1;i<n;i++) {
        if (all[i].first >= now) {
            count++;
            now = all[i].second;
        }
    }
    cout << count << "\n";
} 


int main() {
    get_input();
    sort_vector_pair();
    count();
    return 0;
}
