#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define MAX_RC 30

int r,c;
int a,b,x,y, tp;
vector<vector<int>> Map;

vector<vector<pair<int, int>>> country;
vector<int> ncountry;

//ใส่ครั้งละทั้งประเทศ

void get_input() {
    cin >> r >> c >> a >> b >> x >> y; a--; b--; x--; y--;
    for (int i=0;i<r;i++) {
        vector<int> tmp;
        for (int j=0;j<c;j++) {
            cin >> tp;
            tmp.push_back(tp);
        }
        Map.push_back(tmp);
        tmp.clear();
    }
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) {
    //         cout << Map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void sepC() {
    bool visited[r][c];
    memset(visited, 0, sizeof(visited));
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (!visited[i][j]) {
                ncountry.push_back(Map[i][j]);
                vector<pair<int, int>> cty;
                list<pair<int, int>> q;
                visited[i][j] = true;
                q.push_back(make_pair(i, j));
                cty.push_back(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> u = q.front(); q.pop_front();
                    int o = u.first, p = u.second;
                    cty.push_back(make_pair(o, p));
                    if (o > 0 && !visited[o-1][p] && Map[o-1][p] == Map[o][p]) {
                        visited[o-1][p] = true;
                        q.push_back(make_pair(o-1, p));
                    }
                    if (o < r-1 && !visited[o+1][p] && Map[o+1][p] == Map[o][p]) {
                        visited[o+1][p] = true;
                        q.push_back(make_pair(o+1, p));
                    }
                    if (p > 0 && !visited[o][p-1] && Map[o][p-1] == Map[o][p]) {
                        visited[o][p-1] = true;
                        q.push_back(make_pair(o, p-1));
                    }
                    if (p < c-1 && !visited[o][p+1] && Map[o][p+1] == Map[o][p]) {
                        visited[o][p+1] = true;
                        q.push_back(make_pair(o, p+1));
                    }
                }
                country.push_back(cty);
            }
        }
    }
}

//print layer
void print_layer(int layer[MAX_RC][MAX_RC]) {
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cout << layer[i][j] << " ";
        }
        cout << "\n";
    }
    // usleep(500000);
    // system("clear");
}


void BFS() {
    int layer[MAX_RC][MAX_RC];
    memset(layer, -1, sizeof(layer));
    int ind;
    for (int i=0;i<country.size();i++) {
        if (Map[a][b] == ncountry[i]) {
            ind = i;
            break;
        }
    }
    list<pair<int, int>> q;
    for (int i=0;i<country[ind].size();i++) {
        q.push_back(make_pair(country[ind][i].first, country[ind][i].second));
        layer[country[ind][i].first][country[ind][i].second] = 0;
    }
    while (!q.empty())  {
        pair<int, int> u = q.front(); q.pop_front();
        int o = u.first, p = u.second;
        if (o > 0 && layer[o-1][p] == -1 && Map[o-1][p] != Map[o][p]) {
            for (int i=0;i<country.size();i++) {
                if (Map[o-1][p] == ncountry[i]) {
                    ind = i;
                    break;
                }
            }
            for (int i=0;i<country[ind].size();i++) {
                q.push_back(make_pair(country[ind][i].first, country[ind][i].second));
                layer[country[ind][i].first][country[ind][i].second] = layer[o][p] + 1;
            }
        }
        if (o < r-1 && layer[o+1][p] == -1 && Map[o+1][p] != Map[o][p]) {
            for (int i=0;i<country.size();i++) {
                if (Map[o+1][p] == ncountry[i]) {
                    ind = i;
                    break;
                }
            }
            for (int i=0;i<country[ind].size();i++) {
                q.push_back(make_pair(country[ind][i].first, country[ind][i].second));
                layer[country[ind][i].first][country[ind][i].second] = layer[o][p] + 1;
            }
        }
        if (p > 0 && layer[o][p-1] == -1 && Map[o][p-1] != Map[o][p]) {
            for (int i=0;i<country.size();i++) {
                if (Map[o][p-1] == ncountry[i]) {
                    ind = i;
                    break;
                }
            }
            for (int i=0;i<country[ind].size();i++) {
                q.push_back(make_pair(country[ind][i].first, country[ind][i].second));
                layer[country[ind][i].first][country[ind][i].second] = layer[o][p] + 1;
            }
        }
        if (p < c-1 && layer[o][p+1] == -1 && Map[o][p+1] != Map[o][p]) {
            for (int i=0;i<country.size();i++) {
                if (Map[o][p+1] == ncountry[i]) {
                    ind = i;
                    break;
                }
            }
            for (int i=0;i<country[ind].size();i++) {
                q.push_back(make_pair(country[ind][i].first, country[ind][i].second));
                layer[country[ind][i].first][country[ind][i].second] = layer[o][p] + 1;
            }
        }
    }
    //print_layer(layer);
    cout << layer[x][y] << "\n";
}



int main() {
    get_input();
    sepC();
    BFS();
    return 0;
}