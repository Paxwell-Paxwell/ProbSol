#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, x, y, z, f, count = 0;
    cin >> N >> M;
    int i, j;
    vector<int> adjacent[N];
    bool unvisit[N];
    
    for (i=0;i<N;i++) {
      unvisit[i] = true;
    }

    for (i=0;i<M;i++) {
        cin >> x >> y; x--; y--;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    for (i=0;i<N;i++) {
        if (!unvisit[i]) continue;
        //cout << "Check @" << (i + 1) << "\n";
        list<int> queue;
        queue.push_back(i);
        unvisit[i] = false;
        while (!queue.empty()) {
            f = queue.front();
            queue.pop_front();

            for(z=0;z<adjacent[f].size();z++) {
                if (unvisit[adjacent[f][z]]) {
                    queue.push_back(adjacent[f][z]);
                    unvisit[adjacent[f][z]] = false;
                }
            }
        }
        count++;
    }
    
    cout << count << "\n";     
    return 0;
}