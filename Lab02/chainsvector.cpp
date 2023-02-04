#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N, i, j, n;
    int start = 1;
    cin >> L >> N;
    map<int, vector<int>> All_Chain;
    map<int, int> Pair;
    for (i=0;i<L;i++) {
        cin >> n;
        vector<int> normal;
        for (j=0;j<n;j++) {
          normal.push_back(start + j);
          }
        vector<int> reverse(reverse_iterator<int*>(normal.end()), reverse_iterator<int*>(normal.begin()));

        std::cout << "Original vector: ";
        for (int element : normal) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        std::cout << "Reversed vector: ";
        for (int element : reverse) {
            std::cout << element << " ";
        }
        std::cout << std::endl;


        /*if (i == 0) pointer = node_normal;
        else {
            All_Chain[start] = node_normal;
            All_Chain[start + n - 1] = node_reverse;
            Pair[start] = start + n - 1;
            Pair[start + n - 1] = start;
        }*/
        start += n; 
    }

    /*char command;
    int num, X, arr[N];
    for (i=0;i<N;i++) {
        cin >> command;
        switch (command) {
        case 'F':
            if (pointer->next != NULL) pointer = pointer->next;
            break;
        case 'B':
            if (pointer->back != NULL) pointer = pointer->back;
            break;
        case 'C':
            cin >> X;
            if (pointer->next != NULL) {
                Node *nor = NULL, *rev = NULL, *las = NULL;
                Node *tmp = pointer->next;

                int first = tmp->data, end;
                while (tmp != NULL) {
                  if (tmp->next == NULL) end = tmp->data;
                  append_node(&nor, &las, tmp->data);
                  insert_node(&rev, tmp->data);
                  tmp = tmp->next;
                }
                if (first == end) {
                  All_Chain[first] = nor;
                  Pair[first] = end;
                } else {
                  All_Chain[first] = nor;
                  All_Chain[end] = rev;
                  Pair[first] = end;
                  Pair[end] = first;
                }
            }
            Node *add = All_Chain.at(X);

            pointer->next = add;
            add->back = pointer;

            All_Chain.erase(X);
            All_Chain.erase(Pair[X]);

            int itmp = Pair[X];
            Pair.erase(X);
            Pair.erase(itmp);

            pointer = pointer->next;
            break;
        }
        cout << pointer->data << "\n";
    }*/
    return 0;
}