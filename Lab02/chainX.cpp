#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* back;
};

void append_node(Node **base, Node **last, int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = NULL;
    if (*base == NULL) {
        new_node->back = NULL;
        *base = new_node;
        *last = new_node;
    } else {
        new_node->back = *last;
        (*last)->next = new_node;
        *last = new_node;
    }
}

void insert_node(Node **base, int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = x;
    new_node->back = NULL;
    new_node->next = *base;
    if (*base != NULL) {
      (*base)->back = new_node;
    }
    *base = new_node;
}

int main() {
    int L, N;
    cin >> L >> N;
    int i, j;
    Node* chains[100001];
    int x, start = 1;
    for (i=0;i<L;i++) {
        Node *nf = NULL, *nl = NULL, *r = NULL;
        cin >> x;
        for (j=0;j<x;j++) {
            append_node(&nf, &nl, start + j);
            insert_node(&r, start + j);
        }
        chains[start] = nf;
        chains[start + x - 1] = r;
        start += x;
    }

    Node *robot = chains[1];

    for (i=0;i<N;i++) {
        char command;
        int X;
        cin >> command;
        switch (command) {
        case 'F':
            if (robot->next != NULL) robot = robot->next;
            break;
        case 'B':
            if (robot->back != NULL) robot = robot->back;
            break;
        case 'C':
            cin >> X;
            if (robot->next != NULL) {
                Node *tmp = robot->next;
                tmp->back = NULL;

                Node *nor = tmp;
                Node *rev = NULL;
                while (tmp != NULL) {
                    insert_node(&rev, tmp->data);
                    tmp = tmp->next;
                }
                
                chains[nor->data] = nor;
                chains[rev->data] = rev;
            }

            Node *add_node = chains[X];
            robot->next = add_node;
            add_node->back = robot;

            robot = robot->next;
            break;
        }
        if (robot != NULL) cout << robot->data << "\n";
    }
    return 0;
}