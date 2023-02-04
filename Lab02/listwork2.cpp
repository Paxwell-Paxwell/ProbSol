#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

void node_insert(node **front, node **back, int x) {
    node *new_node = (node *)malloc(sizeof(node *)), *tmp;
    tmp = *front;
    new_node->data = x;
    new_node->next = tmp;

    if (tmp == NULL) *back = new_node;
    *front = new_node;
}

void node_delete(node **front, node **back, int index) {
    int count;
    node *tmp = *front;
    node *tmp2 = *back;
    node *del = NULL;
    count = 1;
    if (index == 1) {
        *front = tmp->next;
        free(tmp);
        }
    else {
        while (tmp != NULL) {
            if (count == index - 1) {
                del = tmp->next;
                if (del->next == NULL) {
                    *back = tmp;
                    }
                tmp->next = tmp->next->next;
                free(del);
                break;
            }
            tmp = tmp->next;
            count++;
        }
    }
}

void node_append(node **front, node **back, int x) {
    node *new_node = (node *)malloc(sizeof(node *)), *tmp;
    tmp = *back;
    new_node->data = x;
    new_node->next = NULL;


    if (tmp == NULL) {
        *front = new_node;
    } else {
        tmp = *back;
        tmp->next = new_node;
        *back = new_node;
    }
}


int main() {
    int n, i, count = 0;
    char command;
    int num;
    node *front = NULL;
    node *back = NULL;
    node *tmp;
    cin >> n;
    for (i=0;i<n;i++) {
        cin >> command >> num;
        if (command == 'I') {
            node_insert(&front, &back, num);
            count++;
        }
        else if (command == 'D') {
            if (num > count) continue;
            node_delete(&front, &back, num);
            count--;
        }
        else if (command == 'A') {
            node_append(&front, &back, num);
            count++;
        }
        
    }
    node *tmpx = front; 
    while (tmpx != NULL) {
        cout << tmpx->data << "\n";
        tmpx = tmpx->next;
    }
    
    return 0;
}