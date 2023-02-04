#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

bool nhos[MAX_N];
bool shos[MAX_N];

bool checker[MAX_N];

vector<int> hospital;
vector<int> shospital;
vector<int> nhospital;
vector<int> adjacent[MAX_N];
vector<int> safe_village;



int n, m, k, h; 
int u, v, a;

void Push(int u) {
    if (!checker[u]) {
        safe_village.push_back(u);
        checker[u] = true;
    }
}


void get_input() {
    cin >> n >> m >> k >> h;
    for (int i = 0; i < k; i++) {
        cin >> a; a--;
        hospital.push_back(a);
    }
    for (int i = 0; i < k; i++) {
        cin >> u;
        if (u) {
            shospital.push_back(hospital[i]);
            shos[hospital[i]] = true;
        }
        else {
            nhospital.push_back(hospital[i]);
            nhos[hospital[i]] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v; u--; v--;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

void BFS(vector<int> hospital, int far) {
    queue<int> q;
    vector<int> layer(n, -1);
    for (int hos : hospital) {
        q.push(hos);
        layer[hos] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (layer[u] <= far) {
            Push(u);
        }
        for (int i = 0; i < adjacent[u].size(); i++) {
            int v = adjacent[u][i];
            if (layer[v] == -1 || layer[v] > layer[u] + 1) {
                layer[v] = layer[u] + 1;
                q.push(v);
            }
        }
    }
}

void check_safe_village() {
    //Special
    BFS(shospital, 2 * h);
    //Normal
    BFS(nhospital, h);
    cout << safe_village.size() << "\n";
}

// Main function
int main() {
    get_input();
    check_safe_village();
    return 0;
}