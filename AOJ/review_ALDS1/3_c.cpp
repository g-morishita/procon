#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *prev;
  Node *next;
};

// the pointer that indicates the first element
Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->prev = nil;
  nil->next = nil;
}

Node* listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while (cur != nil) {
    if (isf++) cout << " ";
    cout << cur->key;
    cur = cur->next;
  }
  cout << endl;
}

void deleteNode(Node *t) {
  if (t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main() {
  init();
  int n, v;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "insert") {
      cin >> v;
      insert(v);
    } else if (s == "deleteFirst") {
      deleteFirst();
    } else if (s == "deleteLast") {
      deleteLast();
    } else if (s == "delete") {
      cin >> v;
      deleteNode(listSearch(v));
    }
  }
  printList();
}
