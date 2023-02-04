#include<bits/stdc++.h>
using namespace std;

struct question {
    int r, c;
    int a, b;
};

int n, q;
vector<string> Map;
vector<question> Aq;

void get_input() {
    cin >> n >> q;
    Map.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
    }
    Aq.resize(q);
    for (int i=0;i<q;i++) {
        cin >> Aq[i].r >> Aq[i].c >> Aq[i].a >> Aq[i].b; Aq[i].r--; Aq[i].c--; Aq[i].a--; Aq[i].b--;
    }
}

//this can't pass door anymore
int BFSs(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    bool visited[n][n];
    memset(visited, false, sizeof(visited));
    Queue.push_back({r, c});
    visited[r][c] = true;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            cout << "yes" << "\n";
            return 1;
        }
        if (x + 1 < n && Map[x + 1][y] != '#' && Map[x + 1][y] != 'O' && !visited[x + 1][y]) {
            Queue.push_back({x + 1, y});
            visited[x + 1][y] = true;
        }
        if (x - 1 >= 0 && Map[x - 1][y] != '#' && Map[x - 1][y] != 'O' && !visited[x - 1][y]) {
            Queue.push_back({x - 1, y});
            visited[x - 1][y] = true;
        }
        if (y + 1 < n && Map[x][y + 1] != '#' && Map[x][y + 1] != 'O' && !visited[x][y + 1]) {
            Queue.push_back({x, y + 1});
            visited[x][y + 1] = true;
        }
        if (y - 1 >= 0 && Map[x][y - 1] != '#' && Map[x][y - 1] != 'O' && !visited[x][y - 1]) {
            Queue.push_back({x, y - 1});
            visited[x][y - 1] = true;
        }
    }
    return 0;
}

//this can still go if encounter a door
void BFS(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    bool visited[n][n];
    memset(visited, false, sizeof(visited));
    Queue.push_back({r, c});
    visited[r][c] = true;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            cout << "yes" << "\n";
            return;
        }
        if (x + 1 < n && Map[x + 1][y] != '#' && !visited[x + 1][y]) {
            if (Map[x + 1][y] == 'O') {
                if (BFSs(x + 1, y, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x + 1, y});
                visited[x + 1][y] = true;
            }
        }
        if (x - 1 >= 0 && Map[x - 1][y] != '#' && !visited[x - 1][y]) {
            if (Map[x - 1][y] == 'O') {
                if (BFSs(x - 1, y, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x - 1, y});
                visited[x - 1][y] = true;
            }
        }
        if (y + 1 < n && Map[x][y + 1] != '#' && !visited[x][y + 1]) {
            if (Map[x][y + 1] == 'O') {
                if (BFSs(x, y + 1, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x, y + 1});
                visited[x][y + 1] = true;
            }
        }
        if (y - 1 >= 0 && Map[x][y - 1] != '#' && !visited[x][y - 1]) {
            if (Map[x][y - 1] == 'O') {
                if (BFSs(x, y - 1, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x, y - 1});
                visited[x][y - 1] = true;
            }
        }
    }
    cout << "no" << "\n";
}

void Answer() {
    for (auto ques : Aq) {
        BFS(ques.r, ques.c, ques.a, ques.b);
    }
}

int main()
{
    get_input();
    Answer();
    return 0;
}
