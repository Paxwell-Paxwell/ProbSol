#include<bits/stdc++.h>
using namespace std;

#define MAX_N 20

int n, k;

vector<vector<int>> Map;
vector<pair<int, int>> adjacent[MAX_N][MAX_N];

//print all elements in each adjacent
void print_adjacent() {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << Map[i][j] << " adjacent[" << i << "][" << j << "] = ";
            for (auto x : adjacent[i][j]) {
                cout << Map[x.first][x.second] << " ";
            }
            cout << endl;
        }
    }
}

void get_input() {
    cin >> n >> k;
    Map.resize(n);
    for (int i = 0; i < n; i++) {
        Map[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i > 0 && Map[i - 1][j] <= Map[i][j] + k) {
                adjacent[i][j].push_back(make_pair(i - 1, j));
            }
            if (i < n - 1 && Map[i + 1][j] <= Map[i][j] + k) {
                adjacent[i][j].push_back(make_pair(i + 1, j));
            }
            if (j > 0 && Map[i][j - 1] <= Map[i][j] + k) {
                adjacent[i][j].push_back(make_pair(i, j - 1));
            }
            if (j < n - 1 && Map[i][j + 1] <= Map[i][j] + k) {
                adjacent[i][j].push_back(make_pair(i, j + 1));
            }
        }
    }
    //print_adjacent();
}

void BFS() {
    list<pair<int, int>> queue;
    bool visited[MAX_N][MAX_N];
    memset(visited, false, sizeof(visited));
    queue.push_back(make_pair(0, 0));
    visited[0][0] = true;
    while (!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop_front();
        for (auto next : adjacent[current.first][current.second]) {
            if (!visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                queue.push_back(next);
            }
            if (next.first == n - 1 && next.second == n - 1) {
                cout << "yes" << "\n";
                return;
            }
        }
    }
    cout << "no" << "\n";
}

int main() {
    get_input();
    BFS();
    return 0;
}