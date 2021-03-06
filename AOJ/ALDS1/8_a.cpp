#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *parent;
  Node *left;
  Node *right;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;

  Node *z;
  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->parent = NIL;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    int k;
    cin >> s;
    if ( s == "insert") {
      cin >> k;
      insert(k);
    } else if (s == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
  return 0;
}
