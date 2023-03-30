#include <bits/stdc++.h>
using namespace std;

#define MAXP 1005
#define MAXC 35

struct Product {
    int price;
    int weight;
};

//recurrence relation
//MW[i] = Max Price you can get for weight i

class Solution {
    public:
        void run() {
            get_input();
            solve();
        }
    private:
        int n, g;
        int MP[31] = {0};
        vector<Product> products;
        vector<int> groups;
        void get_input() {
            int group;
            cin >> n;
            for (int i = 0; i < n; i++) {
                Product product;
                cin >> product.price >> product.weight;
                products.push_back(product);
            }
            cin >> g;
            for (int i = 0; i < g; i++) {
                cin >> group;
                groups.push_back(group);
            }
        }
        void solve() {
            int ans = 0;
            for (auto product : products) {
                for (int i = 30; i >= product.weight; i--) {
                    MP[i] = max(MP[i], MP[i - product.weight] + product.price);
                }
            }
            for (auto group : groups) {
                ans += MP[group];
            }
            cout << ans << endl;
        }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution solution;
        solution.run();
    }
    return 0;
}