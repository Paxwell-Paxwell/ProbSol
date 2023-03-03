#include<bits/stdc++.h>
using namespace std;

//A[i] = max(A[i-1], A[i-1 and remove all overlap] + w[i])

#define MAXN 1000

struct task {
    long long int start, end;
    int weight, index;
    bool operator<(const task &t) const {
        return end < t.end;
    }
};

int n;
vector<task> All_task;
vector<int> saveWeight(MAXN + 1, -1);
vector<vector<int>> saveSeq(MAXN + 1);

void get_input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        task t;
        cin >> t.start >> t.end >> t.weight;
        t.index = i + 1;
        All_task.push_back(t);  
    }
    sort(All_task.begin(), All_task.end());
}

int lastNonOverlap(int ind) {
    for (int i = ind - 1; i >= 0; i--) {
        if (All_task[i].end <= All_task[ind].start)
            return i;
    }
    return -1;
}

int Max_Weight() {
    saveWeight[0] = All_task[0].weight;
    saveSeq[0].push_back(All_task[0].index);
    for (int i = 1; i < n; i++) {
        int last = lastNonOverlap(i);
        int pick = All_task[i].weight;
        int not_pick = saveWeight[i - 1];
        if (last != -1)
            pick += saveWeight[last];
        saveWeight[i] = max(pick, not_pick);
        if (pick > not_pick) {
            if (last != -1)
                saveSeq[i] = saveSeq[last];
                saveSeq[i].push_back(All_task[i].index);
        }
        else 
            saveSeq[i] = saveSeq[i - 1];
    } 
    return saveWeight[n - 1];
}

int main() {
    get_input();
    cout << Max_Weight() << "\n";
    cout << saveSeq[n - 1].size() << "\n";
    for (int i = 0; i < saveSeq[n - 1].size(); i++)
        cout << saveSeq[n - 1][i] << " ";
    cout << "\n";
    return 0;
}
