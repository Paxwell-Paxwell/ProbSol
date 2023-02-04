#include <bits/stdc++.h>
using namespace std;

struct Node {
  long long int data;
  Node* next;
  Node* back;
};


void append_node(Node **base, Node **last, long long int x) {
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

void insert_node(Node **base, long long int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = x;
    new_node->back = NULL;
    new_node->next = *base;

    if (*base != NULL) {
      (*base)->back = new_node;
    }
    *base = new_node;

}

void print(Node *x, Node *y) {
  Node *z;
  while (x != NULL) {
    if (x == y) cout << "|" << x->data << " ";
    else cout << x->data << " ";
    x = x->next;
    if (x->next == NULL) z = x;
  }
  cout << "\n";
  while (z != NULL)
  {
    if (z == y) cout << "|" << z->data << " ";
    else cout << z->data << " ";
    z = z->next;
  }
  cout << "\n";
}

int main() {
    long long int L, N, i, itmp;
    long long int j, n, X, start = 1;
    char command;


    //not found key
    //segment error null->data
    // 
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> N;
    map<long long int, Node*> All_Chain;
    map<long long int, long long int> Pair;
    Node *pointer = NULL, *head = NULL, *add = NULL;

    
    for (i=0;i<L;i++) {
        cin >> n;
        
        Node *node_normal = NULL, *node_reverse = NULL, *last_normal = NULL;
        for (j=0;j<n;j++) {
          append_node(&node_normal, &last_normal, start + j);
          insert_node(&node_reverse, start + j);
          }
        if (i == 0) pointer = node_normal;
        else {
            All_Chain[start] = node_normal;
            All_Chain[start + n - 1] = node_reverse;
            Pair[start] = start + n - 1;
            Pair[start + n - 1] = start;
        }
        //print(node_normal, NULL);
        //print(node_reverse, NULL);
        start += n; 
    }

    head = pointer;
    print(head, pointer);
    //cout << "@" << pointer->data << "\n";

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
                Node *nor = NULL, *las = NULL;
                Node *rev = NULL;
                Node *tmp = pointer->next;

                tmp->back = NULL;
                int first = tmp->data, end;
                while (tmp != NULL) {
                  if (tmp->next == NULL) end = tmp->data;
                  append_node(&nor, &las, tmp->data);
                  insert_node(&rev, tmp->data);
                  tmp = tmp->next;
                }
                All_Chain[first] = nor;
                All_Chain[end] = rev;
                Pair[first] = end;
                Pair[end] = first;
                
            }
            if (All_Chain.count(X)) {
              add = All_Chain[X];
            } else {
              continue;
            }
            pointer->next = add;
            add->back = pointer;
            pointer = add;
            break;
        }
        //cout << pointer->data << "\n";
        print(head, pointer);

    }
    return 0;
}