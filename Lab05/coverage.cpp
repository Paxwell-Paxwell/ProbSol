#include<bits/stdc++.h>
using namespace std;

#define MAX_I 100000

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

int n, m, l, r;

void Problem_Solver() {
    cin >> n;
    for (int i=0;i<n;i++) {
        vector<pair<int, int>> plate;
        vector<int> ans;
        cin >> m;
        cin >> l >> r;
        while (l != 0 || r != 0) {
            plate.push_back(make_pair(l, r));
            cin >> l >> r;
        }
        sort(plate.begin(), plate.end(), cmp);
        int current = 0, far_ind = 0;
        while (current < m) {
            int ncurrent = current;
            int farth = current;
            for (int i=0;i<plate.size();i++) {
                //find plate that start before current and go farthest
                if (plate[i].first > current) {
                    break;
                }
                if (plate[i].second > farth) {
                    farth = plate[i].second;
                    far_ind = i;
                }
            }
            //check break
            if (current == farth) {
                break;;
                //This mean it can't go any more than current
            }
            current = farth;
            ans.push_back(far_ind);
        }
        if (current >= m) {
            int siz = ans.size();
            cout << siz << "\n";
            for (int j=0;j<siz;j++) {
                cout << plate[ans[j]].first << " " << plate[ans[j]].second << "\n";
            }
        }
        else {
            cout << "0\n";
        }
        if (i != n - 1) cout << "\n";
    }
}

int main() {
    Problem_Solver();
    return 0;
}