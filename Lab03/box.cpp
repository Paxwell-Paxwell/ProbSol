#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 30

/*
x0
00
*/

int n, m;
vector< vector<char> > Map;
bool visited[MAX_NUM][MAX_NUM];


bool box_in(int x, int y) {
    if (x + 1 >= m || y + 1 >= n) {
        return false;
        }
    if (Map[y][x] == '#' || Map[y+1][x] == '#' || Map[y+1][x+1] == '#' || Map[y][x+1] == '#') {
        return false;
    }
    return true;
}

void get_input() {
    cin >> n >> m;
    char inp;
    for (int i=0;i<n;i++) {
        vector<char> temp;
        for (int j=0;j<m;j++) {
            cin >> inp;
            temp.push_back(inp);
        }
        Map.push_back(temp);
    }
}

bool is_path(int x) {
    //bfs
    if (!box_in(x, 0)) return false;

    list<pair<int, int> > queue;
    queue.push_back(make_pair(x, 0));
    visited[0][x] = true;

    while (!queue.empty()) {
        int x1 = queue.front().first, y1 = queue.front().second;
        queue.pop_front();

        if (y1 == n - 2) {
            return true;
        }

        if (x1 > 0 && box_in(x1 - 1, y1) && !visited[y1][x1 - 1]) {
            visited[y1][x1 - 1] = true;
            queue.push_back(make_pair(x1 - 1, y1));
        }
        if (y1 > 0 && box_in(x1, y1 - 1) && !visited[y1 - 1][x1]) {
            visited[y1 - 1][x1] = true;
            queue.push_back(make_pair(x1, y1 - 1));
        }
        if (x1 + 1 <= m && box_in(x1 + 1, y1) && !visited[y1][x1 + 1]) {
            visited[y1][x1 + 1] = true;
            queue.push_back(make_pair(x1 + 1, y1));
        }
        if (y1 + 1 <= n && box_in(x1, y1 + 1) && !visited[y1 + 1][x1]) {
            visited[y1 + 1][x1] = true;
            queue.push_back(make_pair(x1, y1 + 1));
        }
    }
    return false;
}

bool path_check() {
    for (int i=0;i<m;i++) {
        if (is_path(i)) {
            return true;
        }
    }
    return false;
}

int main() {
    get_input();
    cout << (path_check()? "yes" : "no") << "\n";
    return 0;
}
