#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BinaryNode {
  int key;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode *parent;
};

BinaryNode *root, *NIL;

void insert(int key) {
  BinaryNode *z;
  BinaryNode *y {NIL};
  BinaryNode *x {root};

  z = (BinaryNode *)malloc(sizeof(BinaryNode));
  z->key = key;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (x->key < z->key) {
      x = x->right;
    } else {
      x = x->left;
    }
  }

  if (y == NIL) {
    root = z;
  } else {
    if (y->key < z->key) {
      y->right = z;
    } else {
      y->left = z;
    }
  }
}

bool find(int key, BinaryNode *u) {
  while (u != NIL) {
    if (u->key == key) {
      return true;
    } else if (u->key > key) {
      u = u->left;
    } else {
      u = u->right;
    }
  }

  return false;
}

void preorderPrint(BinaryNode *u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preorderPrint(u->left);
  preorderPrint(u->right);
}

void inorderPrint(BinaryNode *u) {
  if (u == NIL) return;
  inorderPrint(u->left);
  cout << " " << u->key;
  inorderPrint(u->right);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int key;
    string s;
    cin >> s;
    if (s == "insert") {
      cin >> key;
      insert(key);
    } else if (s == "print") {
      inorderPrint(root);
      cout << endl;
      preorderPrint(root);
      cout << endl;
    } else if (s == "find") {
      cin >> key;
      if (find(key, root)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
