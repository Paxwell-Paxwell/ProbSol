#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* back;
};

void append_node(Node **base, int x) {
    Node *new_node = (Node *)malloc(sizeof(Node)), *tmp;

    tmp = *base;
    new_node->data = x;
    new_node->next = NULL;

    if (tmp == NULL) {
      new_node->back = NULL;
      *base = new_node;
    } else {
      while (tmp->next != NULL) {
        tmp = tmp->next;
      }
      tmp->next = new_node;
      new_node->back = tmp;
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
    int L, N, i, j, n;
    cin >> L >> N;
    map<int, Node*> All_Chain;
    map<int, int> Pair;
    int start = 1;
    Node *pointer = NULL;
    Node *head = NULL;
    for (i=0;i<L;i++) {
        cin >> n;
        //create normal linked list and reverse linked list
        Node *node_normal = NULL;
        Node *node_reverse = NULL;
        for (j=0;j<n;j++) {
          append_node(&node_normal, start + j);
          insert_node(&node_reverse, start + j);
          }
        //cout << "Add: " << start << " " << start + n - 1 << "\n"; 
        //set first robot position
        if (i == 0) pointer = node_normal;
        //set Chain and pair
        else {
            All_Chain[start] = node_normal;
            All_Chain[start + n - 1] = node_reverse;
            Pair[start] = start + n - 1;
            Pair[start + n - 1] = start;
        }

        start += n; 
    }
    head = pointer;
    Node *tmp;
    //cout << pointer->data << "\n";
    //now robot is on 1 
    //cout << "Pointer Now @" << pointer->data << "\n";
    char command;
    int num, X = 0, arr[N];
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
            //there are to case 1. pointer at the end 2. and not the first case
            cin >> X;
            //cout << X << " ";
            if (pointer->next != NULL) {
                Node *nor = NULL;
                Node *rev = NULL;
                Node *tmp = pointer->next;

                int first = tmp->data, end;
                while (tmp != NULL) {
                  if (tmp->next == NULL) end = tmp->data;
                  append_node(&nor, tmp->data);
                  insert_node(&rev, tmp->data);
                  tmp = tmp->next;
                }
                //cout << "Add: " << first << " " << end << "\n"; 
                All_Chain[first] = nor;
                All_Chain[end] = rev;
                Pair[first] = end;
                Pair[end] = first;
            }
                //get a node that has data equal to X
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
        //cout << "Command : " << command << " Pointer Now @" << pointer->data << "\n";      
        /*tmp = head;
        while (tmp != NULL)
        {
          cout << tmp->data << " ";
          tmp = tmp->next;
        }
        cout << "\n";*/
        arr[i] = pointer->data;
    }
    for (i=0;i<N;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}