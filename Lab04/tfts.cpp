#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000

struct path {
    int to;
    int time;
    bool s;
};

int n, m;
vector<path> adjacent[MAX_N];
int shortest[MAX_N];
int shortest_spe[MAX_N];
bool visited[MAX_N];
bool visited_spe[MAX_N];
bool is_spe;


bool sorttime(const path &a,const path &b) {
    return (a.time < b.time);
}

void sort_adjacent() {
    for (int i=0;i<n;i++) {
        sort(adjacent[i].begin(), adjacent[i].end(), sorttime);
        shortest[i] = -1;
        shortest_spe[i] = -1;
    }
}

void get_input() {
    cin >> n >> m;
    int a, b, c;
    bool s;
    for (int i=0;i<m;i++) {
        cin >> a >> b >> c >> s; a--; b--;
        adjacent[a].push_back({b, c, s});
        adjacent[b].push_back({a, c, s});
    }
    sort_adjacent();
}

int find_min() {
    int min = INT_MAX;
    int index = -1;
    for (int i=0;i<n;i++) {
        if (shortest[i] != -1 && !visited[i] && shortest[i] < min) {
            index = i;
            min = shortest[i];
            is_spe = false;
        }
    }
    for (int i=0;i<n;i++) {
        if (shortest_spe[i] != -1 && !visited_spe[i] && shortest_spe[i] < min) {
            index = i;
            min = shortest_spe[i];
            is_spe = true;
        }
    }
    return index;
}
 
void Dijkstra() {
    shortest[0] = 0;
    int m = find_min();
    while (m != -1) {
        for (int j=0;j<adjacent[m].size();j++) {
            int un = adjacent[m][j].to, ut = adjacent[m][j].time, us = adjacent[m][j].s;
            if (is_spe) {
                if (us)
                    continue;
                else if (shortest_spe[un] == -1 || shortest_spe[un] > shortest_spe[m] + ut) {
                    shortest_spe[un] = shortest_spe[m] + ut;
                } 
            }
            else {
                if (!us && (shortest[un] == -1 || shortest[un] > shortest[m] + ut)) {
                    shortest[un] = shortest[m] + ut;
                }
                else if (us && (shortest_spe[un] == -1 || shortest_spe[un] > shortest[m] + ut)) {
                    shortest_spe[un] = shortest[m] + ut;
                }
            }
        }
        if (is_spe)
            visited_spe[m] = true;
        else 
            visited[m] = true;
        m = find_min();
    }
    if (shortest_spe[n - 1] == -1) 
        cout << shortest[n - 1] << "\n";
    else if (shortest[n - 1] == -1) 
        cout << shortest_spe[n - 1] << "\n";
    else 
        if (shortest[n - 1] > shortest_spe[n - 1]) 
            cout << shortest_spe[n - 1] << "\n";
        else 
            cout << shortest[n - 1] << "\n";
}




int main() {
    get_input();
    Dijkstra();
    return 0;
}
