#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define MAX_RC 50

int r, c;
int a, b, x, y;
vector<string> Map;
vector<int> Ans;

void get_input() {
    cin >> r >> c;
    cin >> a >> b >> x >> y; a--; b--; x--; y--;
    Map.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> Map[i];
    }
}

void print_map(int layer[MAX_RC][MAX_RC], int ss, bool clear) {
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (layer[i][j] != -1) {
                cout << ss;
            }
            else  {
                cout << Map[i][j];
            }
        }
        cout << "\n";
    }
    cout << "\n";
    usleep(2000);
    if (clear)
        system("clear");
}

//print all element in list
void print_list(list<pair<int, int>> l) {
    for (auto i = l.begin(); i != l.end(); i++) {
        cout << "(" << i->first << ", " << i->second << ") ";
    }
    cout << "\n";
}


void BFSs(int o, int p, int lay[MAX_RC][MAX_RC], int start) {
    int layer[MAX_RC][MAX_RC];
    memcpy(layer, lay, MAX_RC*MAX_RC*sizeof(int));
    layer[o][p] = start;
    list<pair<int, int>> queue;
    queue.push_back(make_pair(o, p));
    while (!queue.empty()) {
        pair<int, int> p = queue.front();
        queue.pop_front();
        int i = p.first, j = p.second;
        if (i == x && j == y) {
            Ans.push_back(layer[i][j]);
        }
        print_list(queue);
        print_map(layer, 1, true);
        if (i > 0 && Map[i-1][j] == '.' && (layer[i-1][j] > layer[i][j] + 1 || layer[i-1][j] == -1)) {
            layer[i-1][j] = layer[i][j] + 1;
            queue.push_back(make_pair(i-1, j));
        }
        if (i < r-1 && Map[i+1][j] == '.' && (layer[i+1][j] > layer[i][j] + 1 || layer[i+1][j] == -1)) {
            layer[i+1][j] = layer[i][j] + 1;
            queue.push_back(make_pair(i+1, j));
        }
        if (j > 0 && Map[i][j-1] == '.' && (layer[i][j-1] > layer[i][j] + 1 || layer[i][j-1] == -1)) {
            layer[i][j-1] = layer[i][j] + 1;
            queue.push_back(make_pair(i, j-1));
        }
        if (j < c-1 && Map[i][j+1] == '.' && (layer[i][j+1] > layer[i][j] + 1 || layer[i][j+1] == -1)) {
            layer[i][j+1] = layer[i][j] + 1;
            queue.push_back(make_pair(i, j+1));
        }
        
    }
    
}



void BFS() {
    int layer[MAX_RC][MAX_RC];
    memset(layer, -1, sizeof(layer));

    list<pair<int, int>> queue;
    layer[a][b] = 0;
    queue.push_back(make_pair(a, b));
    while (!queue.empty()) {
        pair<int, int> p = queue.front();
        queue.pop_front();
        int i = p.first, j = p.second;
        if (i == x && j == y) {
            Ans.push_back(layer[i][j]);
        }
        print_list(queue);
        print_map(layer, 0, true);
        if (i > 0 && layer[i-1][j] == -1) {
            if (Map[i-1][j] == '.') {
                layer[i-1][j] = layer[i][j] + 1;
                queue.push_back(make_pair(i-1, j));
            }
            if (Map[i-1][j] == '*' && i > 1 && Map[i-2][j] == '.') {
                BFSs(i-2, j, layer, layer[i][j] + 2);
            }
        }
        if (i < r-1 && layer[i+1][j] == -1) {
            if (Map[i+1][j] == '.') {
                layer[i+1][j] = layer[i][j] + 1;
                queue.push_back(make_pair(i+1, j));
            }
            if (Map[i+1][j] == '*' && i < r-2 && Map[i+2][j] == '.') {
                BFSs(i+2, j, layer, layer[i][j] + 2);
            }
        }
        if (j > 0 && layer[i][j-1] == -1) {
            if (Map[i][j-1] == '.') {
                layer[i][j-1] = layer[i][j] + 1;
                queue.push_back(make_pair(i, j-1));
            }
            if (Map[i][j-1] == '*' && j > 1 && Map[i][j-2] == '.') {
                BFSs(i, j-2, layer, layer[i][j] + 2);
            }
        }
        if (j < c-1 && layer[i][j+1] == -1) {
            if (Map[i][j+1] == '.') {
                layer[i][j+1] = layer[i][j] + 1;
                queue.push_back(make_pair(i, j+1));
            }
            if (Map[i][j+1] == '*' && j < c-2 && Map[i][j+2] == '.') {
                BFSs(i, j+2, layer, layer[i][j] + 2);
            }
        }
    }
    int min = INT_MAX;
    if (Ans.size() == 0) {
        cout << "-1\n";
        return;
    }
    for (auto i = Ans.begin(); i != Ans.end(); i++) {
        if (*i < min)
            min = *i;
    }
    cout << min << "\n";
}

int main() {
    get_input();
    BFS();
    return 0;
}