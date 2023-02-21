#include<bits/stdc++.h>
using namespace std;

#define MAX_N 200

struct path {
    int a, b, w;
};

struct compareW {
    bool operator()(path const& p1, path const& p2) {
        return p1.w > p2.w;
    }
};

int n, w;
priority_queue<path, vector<path>, compareW> paths;
int parent[MAX_N];
int weight[MAX_N];



void set_up() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        weight[i] = 1;
    }
}

int find_root(int a) {
    if (a == parent[a]) {
        return a;
    }
    else {
        return find_root(parent[a]);
    }
}

void MST() {
    int mst_weight = 0;
    int max_weight = 0;
    set_up();
    //sort(paths.begin(), paths.end(), cmp);
    priority_queue<path, vector<path>, compareW> tmp = paths;
    while (!tmp.empty()) {
        path temp = tmp.top();
        tmp.pop();
        if (max_weight == n) {
            break;
        }
        int rootA = find_root(temp.a), rootB = find_root(temp.b);
        if (rootA != rootB) {
            if (weight[rootA] >= weight[rootB]) {
                weight[rootA] += weight[rootB];
                if (max_weight < weight[rootA]) {
                    max_weight = weight[rootA];
                }
                parent[rootB] = rootA;
            }
            else {
                weight[rootB] += weight[rootA];
                if (max_weight < weight[rootB]) {
                    max_weight = weight[rootB];
                }
                parent[rootA] = rootB;
            }
            mst_weight += temp.w;
        }
    }
    if (max_weight < n) {
        cout << "-1" << "\n";
    }
    else {
        cout << mst_weight << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w;
    for (int i = 0; i < w; i++) {
        path temp;
        cin >> temp.a >> temp.b >> temp.w; temp.a--; temp.b--;
        paths.push(temp);
        //paths.push_back(temp);
        MST();
    }
    return 0;
}
