#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 30

int n, m;
vector< vector<char> > qMap;
bool visited[MAX_NUM][MAX_NUM];
int two = 0, one = 0;

void get_input() {
    cin >> n >> m;
    
    for (int i=0;i<n;i++) {
        vector<char> temp;
        for (int j=0;j<m;j++) {
            char inp;
            cin >> inp;
            temp.push_back(inp);
            visited[i][j] = false;
        }
        qMap.push_back(temp);
    }
}

void bfs() {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (visited[i][j] || qMap[i][j] == '#') continue;
            //cout << "Run@" << i << " " << j << "\n";
            int count = 0;
            bool a = false, b = false;
            list<pair<int, int> > queue;

            queue.push_back(make_pair(i, j));
            visited[i][j] = true;
            if (qMap[i][j] == '$') a = true;
            if (qMap[i][j] == '*') b = true;
            while (!queue.empty()) {
                int x = queue.front().first, y = queue.front().second;
                queue.pop_front();
                //cout << x << " " << y << "\n";
                if (x - 1 >= 0 && qMap[x - 1][y] != '#' && !visited[x - 1][y]) {
                    //cout << "A\n";
                    visited[x - 1][y] = true;
                    queue.push_back(make_pair(x - 1, y));
                    if (qMap[x - 1][y] == '$') a = true;
                    if (qMap[x - 1][y] == '*') b = true;
                } 
                if (y - 1 >= 0 && qMap[x][y - 1] != '#' && !visited[x][y - 1]) {
                    //cout << "B\n";
                    visited[x][y - 1] = true;
                    queue.push_back(make_pair(x, y - 1));
                    if (qMap[x][y - 1] == '$') a = true;
                    if (qMap[x][y - 1] == '*') b = true;
                }  
                if (x + 1 < n && qMap[x + 1][y] != '#' && !visited[x + 1][y]) {
                    //cout << "C\n";
                    visited[x + 1][y] = true;
                    queue.push_back(make_pair(x + 1, y));
                    if (qMap[x + 1][y] == '$') a = true;
                    if (qMap[x + 1][y] == '*') b = true;
                } 
                if (y + 1 < m && qMap[x][y + 1] != '#' && !visited[x][y + 1]) {
                    //cout << "D\n";
                    visited[x][y + 1] = true;
                    queue.push_back(make_pair(x, y + 1));
                    if (qMap[x][y + 1] == '$') a = true;
                    if (qMap[x][y + 1] == '*') b = true;
                }
                //cout << queue.size() << "\n";
                //cout << "a, b: " << a << " " << b << "\n";
                count++;
            }
            //cout << "Count is " << count << "\n";
            if (a && b) {
                two += count;
                }
            else if (a || b) {
                one += count;
                }
        }
    }
    cout << two << " " << one << "\n";
}

int main() {
    get_input();
    bfs();
    return 0;
}