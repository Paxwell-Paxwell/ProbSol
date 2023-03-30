#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

class Solve {
    public:
        Solve(int l) {
            this->l = l;
        }
        void run() {
            get_input();
            solve();
        }
    private:
        int n, l, ans;
        int memos[MAX][MAX];
        vector<int> cuts;
        void get_input() {
            memset(memos, -1, sizeof(memos));
            int cut;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> cut;
                cuts.push_back(cut);
            }
        }
        int cost(int start, int end, vector<int> cuts) {
            if (cuts.size() == 0)
                return 0;
            if (memos[start][end] != -1)
                return memos[start][end];
            int mn = INT_MAX;
            for (int i=0;i<cuts.size();i++) {
                vector<int> ncuts1, ncuts2;
                ncuts1 = vector<int>(cuts.begin(), cuts.begin() + i);
                ncuts2 = vector<int>(cuts.begin() + i + 1, cuts.end());
                mn = min(mn, end - start + cost(start, cuts[i], ncuts1) + cost(cuts[i], end, ncuts2));
            }
            memos[start][end] = mn;
            return mn;
        }
        void solve() {
            ans = cost(0, l, cuts);
            cout << "The minimum cutting is " << ans << "." << endl;
        }

};


int main() {
    int l;
    while (cin >> l && l != 0) {
        Solve* sol = new Solve(l);
        sol->run();
        delete sol;
    }
    return 0;
}