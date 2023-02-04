#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

void llprint(node *x) {
    while (x != NULL) {
        cout << x->data << "\n";
        x = x->next;
    }
}

void li(node **left, node **right, int x) {
    node *new_node = (node *)malloc(sizeof(node *)), *tmp;
    new_node->data = x;
    //when there is no node
    if (*left == NULL && *right == NULL) {
        new_node->next = NULL;
        *left = new_node;
        *right = new_node;
    }
    else if (*left != NULL) {
        tmp = *left;
        new_node->next = tmp;

        *left = new_node;
    }
}

void ri(node **left, node **right, int x) {
    node *new_node = (node *)malloc(sizeof(node *)), *tmp;
    new_node->data = x;
    new_node->next = NULL;
    //when there is no node
    if (*left == NULL && *right == NULL) {
        *left = new_node;
        *right = new_node;
    }
    else if (*right != NULL) {
        tmp = *right;
        tmp->next = new_node;

        *right = new_node;
    }
}

int lr(node **left, node **right) {
    if (*left == NULL || *right == NULL || *left == *right) return 0;
    node *tmp1 = *left, *tmp2 = *right;
    *left = tmp1->next;

    tmp1->next = NULL;
    tmp2->next = tmp1;
    *right = tmp1; 
    return 0;
}

int rr(node **left, node **right) {
    if (*left == NULL || *right == NULL || *left == *right) return 0;
    node *tmp1 = *left, *tmp2 = *right, *tmp3 = *left;
    //go to the last right one
    while (tmp3 != *right && tmp3->next != *right) {
        tmp3 = tmp3->next;
    }
    tmp3->next = NULL;

    tmp2->next = tmp1;
    *left = tmp2;
    *right = tmp3;
    return 0;
}


int main() {
    int W, i;
    char command[3];
    int num;
    node *left = NULL;
    node *right = NULL;
    cin >> W;
    for (i=0;i<W;i++) {
        cin >> command;
        if (!strcmp(command, "li")) {
            cin >> num;
            li(&left, &right, num);
        }
        else if (!strcmp(command, "ri")) {
            cin >> num;
            ri(&left, &right, num);
        }
        else if (!strcmp(command, "lr")) {
            lr(&left, &right);
        }
        else if (!strcmp(command, "rr")) {
            rr(&left, &right);
        }
        
    }
    llprint(left);
    return 0;
}