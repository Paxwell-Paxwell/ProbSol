#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    int n, i, x, y;
    cin >> n;
    int unused[n];
    fill_n(unused, n, 1);
    node **All = (node **)malloc(sizeof(node *) * n);
    node *node_x, *node_y, *node_tmp, *node_tmp2;
    for (i=0;i<n;i++) {
        node *new_node = (node *)malloc(sizeof(node *));
        new_node->data = i + 1;
        new_node->next = NULL;
        All[i] = new_node;
        }
    for (i=0;i<n-1;i++) {
        //Choose x node to connect at back at y node 
        cin >> x >> y;
        node_x = All[x - 1];
        node_y = All[y - 1];
        unused[x - 1] = 0;
        //case 1: y is alone but x can be alone or not
        if (node_y->next == NULL) {
            node_y->next = node_x;
        }
        //case 2: y is not alone but x is alone
        else if (node_y->next != NULL && node_x->next == NULL) {
            node_tmp = node_y->next;
            node_y->next = node_x;
            node_x->next = node_tmp;
        }
        //case 3: y is not alone and x is also not alone
        else if (node_y->next != NULL && node_x->next != NULL) {
            node_tmp = node_y->next;
            node_y->next = node_x;
            node_tmp2 = node_x->next;
            while (node_tmp2->next != NULL) node_tmp2 = node_tmp2->next;
            node_tmp2->next = node_tmp;
        }
    }

    int index;
    for (i=0;i<n;i++) {
        if (unused[i]) {
            index = i;
            break;
            }
    }
    node *head = All[index];
    while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    cout << endl;
    
    //free memory
    for (i=0;i<n;i++) free(All[i]);
    free(All);
}