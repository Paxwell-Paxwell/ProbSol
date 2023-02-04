#include<bits/stdc++.h>
using namespace std;

struct contract {
    int ccost;
    int costu;
    int weight;
};

int k, n;
vector<int> product;
vector<contract> LofC;

int maxpw = 0;

void get_input() {
    int c, u, w; 
    cin >> k >> n;
    for (int i=0;i<k;i++) {
        cin >> c >> u >> w;
        LofC.push_back(contract{c, u, w});
    }
    for (int i=0;i<n;i++) {
        cin >> c;
        product.push_back(c);
        if (c > maxpw) {
            maxpw = c;
        }
    }
}

int calcost(contract con) {
    int cost = con.ccost, weight = con.weight, costuse = con.costu;
    int count = 0, cweight = 0;
    for (int p : product) {
        if (cweight + p > weight) {
            cweight = 0;
            count++;
        }
        if (cweight + p <= weight) {
            cweight += p;
        }
    }
    if (cweight != 0) {
        count++;
    }
    return cost + costuse * count;
}

void find_eff_cont() {
    int min = INT_MAX;
    for (auto con : LofC) {
        if (con.weight < maxpw) {
            continue;
        }
        if (calcost(con) < min) {
            min = calcost(con);
        }
    }
    cout << min << "\n";
}

int main() {
    get_input();
    find_eff_cont();
    return 0;
}

