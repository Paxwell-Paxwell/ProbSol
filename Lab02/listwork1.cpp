#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

void node_insert(node **base, int x) {
    node *new_node = (node *)malloc(sizeof(node *)), *tmp;
    tmp = *base;
    new_node->data = x;
    new_node->next = tmp;

    *base = new_node;
}

void node_delete(node **base, int index) {
    int count;
    node *tmp = *base;
    node *del = NULL;
    count = 1;
    if (index == 1) *base = tmp->next; 
    else {
        while (tmp != NULL) {
            if (count == index - 1) {
                del = tmp->next;
                tmp->next = tmp->next->next;
                free(del);
                break;
            }
            tmp = tmp->next;
            count++;
        }
    }
    
}


int main() {
    int n, i, count = 0;
    char command;
    int num;
    node *edon = NULL;
    cin >> n;
    for (i=0;i<n;i++) {
        cin >> command >> num;
        if (command == 'I') {
            node_insert(&edon, num);
            count++;
        }
        else if (command == 'D') {
            if (num > count) continue;
            node_delete(&edon, num);
            count--;
        }
    }
    while (edon != NULL) {
        cout << edon->data << "\n";
        edon = edon->next;
    }
    return 0;
}