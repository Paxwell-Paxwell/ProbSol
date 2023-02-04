#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

struct Node{
    int node;
    int distance;
};

int n, m;

int shortest_dis[MAX_N];
bool visited[MAX_N];
vector<pair<int, int> > adjacent[MAX_N];

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

priority_queue<Node, vector<Node>, Compare> minheap;


void get_input() {
    int a, b, w;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        cin >> a >> b >> w; a--; b--;
        adjacent[a].push_back(make_pair(w, b));
        adjacent[b].push_back(make_pair(w, a));
    }
}

void Dijkstra() {
    shortest_dis[0] = 0;
    visited[0] = true;
    minheap.push(Node{0, 0});

    while (!minheap.empty()) {
        Node top = minheap.top();
        minheap.pop();
        int m = top.node;
        //cout << "pop: " << m << "\n";
        for (auto path : adjacent[m]) {
            int to = path.second, weight = path.first;
            if (!visited[to] || shortest_dis[to] > shortest_dis[m] + weight) {
                shortest_dis[to] = shortest_dis[m] + weight;
                minheap.push(Node{to, shortest_dis[to]});
                visited[to] = true;
            }
        }
    }
    cout << shortest_dis[n - 1] << "\n";
}

int main() {
    get_input();
    Dijkstra();
    
}