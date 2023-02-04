#include <bits/stdc++.h>
#include <list>
using namespace std;



int main() {
    int L, N;
    cin >> L >> N;
    int i, j, x, start = 1;
    map<int, list<int>> chains;
    map<int, int> pairs;
    for (i=0;i<L;i++) {
        cin >> x;
        list<int> normal, reverse;
        for (j=0;j<x;j++) {
            normal.push_back(start + j);
            reverse.push_front(start + j);
        }
        chains[start] = normal;
        chains[start + x - 1] = reverse;
        pairs[start] = start + x - 1;
        pairs[start + x - 1] = start;

        start += x;
    }
    int index = 0;
    list<int> main_list = chains[1];

    for (i=0;i<N;i++) {
        char command;
        int X;
        cin >> command;
        switch (command)
        {
        case 'F':
            if (main_list.size() - index > 1) index++;
            break;
        case 'B':
            if (index > 0) index--;
            break;
        case 'C':
            cin >> X;
            if (main_list.size() - index > 1) {
                list<int> sub_list;
                sub_list.splice(sub_list.begin(), main_list, next(main_list.begin(), index + 1), main_list.end());
                list<int> rsub_list(std::reverse_iterator<std::list<int>::iterator>(sub_list.end()),
                         std::reverse_iterator<std::list<int>::iterator>(sub_list.begin()));
                chains[sub_list.front()] = sub_list;
                chains[rsub_list.front()] = rsub_list;
                pairs[sub_list.front()] = rsub_list.front();  
                pairs[rsub_list.front()] = sub_list.front();  
            }
            list<int> add_list = chains[X];
            main_list.insert(main_list.end(), add_list.begin(), add_list.end());
            index++;
        }
        auto it = next(main_list.begin(), index);
        int z = *it;
        cout << z << "\n";
    }


    return 0;
}