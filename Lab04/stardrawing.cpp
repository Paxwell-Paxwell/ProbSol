#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

struct region {
    vector<int> member;
    int num_node;
    int num_edge;
    int adjnum[3] = {0, 0, 0};
};

int n, m;
vector<int> adjacent[MAX_N];
vector<region> uregions;
bool visited[MAX_N];


void get_input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

bool compare(int a[], int b[]) {
    for (int i = 0; i < 3; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void BFS(int start) {
    region reg;
    reg.num_edge = 0;
    reg.num_node = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        reg.member.push_back(u);
        reg.num_node++;
        reg.adjnum[adjacent[u].size()]++;
        for (int i = 0; i < adjacent[u].size(); i++) {
            reg.num_edge++;
            int v = adjacent[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (auto r : uregions) {
        if (r.num_node == reg.num_node && r.num_edge == reg.num_edge && compare(r.adjnum, reg.adjnum)) {
            return;
        }
    }
    uregions.push_back(reg);
}

void get_region() {
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
}

//print all element in each region 
//print node and edge num too
//print array adjnum
void print_region() {
    for (auto r : uregions) {
        cout << "Region: ";
        for (auto u : r.member) {
            cout << u + 1 << " ";
        }
        cout << endl;
        cout << "Number of nodes: " << r.num_node << endl;
        cout << "Number of edges: " << r.num_edge << endl;
        cout << "Adjacency number: ";
        for (int i = 0; i < 3; i++) {
            cout << r.adjnum[i] << " ";
        }
        cout << endl;
    }
}
//write main
int main() {
    get_input();
    get_region();
    //print_region();
    cout << uregions.size() << "\n";
    return 0;
}



