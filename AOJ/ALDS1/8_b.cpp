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

bool find(Node *root, int k) {
  Node *x = root;
  bool is_found = false;
  while (x != NIL) {
    if (k < x->key) {
      x = x->left;
    } else if (k > x->key) {
      x = x->right;
    } else {
      is_found = true;
      break;
    }
  }
  return is_found;
}

void del(int k) {
  Node* x = root; // deleted node
  // find the node whose key is k
  while (x != NIL) {
    if (k < x->key) {
      x = x->left;
    } else if (k > x->key) {
      x = x->right;
    } else {
      break;
    }
  }
  if (x == NIL) return;

  // whne the node has no children
  if (x->right == NIL && x->left == NIL) {
    Node* y = x->right;
    if (x->parent == NIL) {
      root = NIL;
      return;
    }
    if (x->parent->left == x) {
      x->parent->left = NIL;
      x->parent = NIL;
      return;
    } else {
      x->parent->right = NIL;
      x->parent = NIL;
      return;
    }
  } else if (x->right != NIL && x->left != NIL) {
    Node* y = x->right;
    while (y->left != NIL)  {
      y = y->left;
    }
    if (y->right != NIL) {
      y->parent->left = y->right;
      y->right->parent = y->parent;
      x->key = y->key;
      return;
    } else {
      if (y->parent != x) {
        y->parent->left = NIL;
        x->key = y->key;
        return;
      } else {
        x->key = y->key;
        x->right = NIL;
      }
    }
  } else {
    if (x->left != NIL) {
      x->left->parent = x->parent;
      if (x->parent->left == x) {
        x->parent->left = x->left;
      } else {
        x->parent->right = x->left;
      }
      x->left = NIL;
      return;
    } else{
      x->right->parent = x->parent;
      if (x->parent->left == x) {
        x->parent->left = x->right;
      } else {
        x->parent->right = x->right;
      }
      x->right = NIL;
      return;
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
    } else if (s == "find") {
      cin >> k;
      if (find(root, k)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else if (s == "delete") {
      cin >> k;
      del(k);
    }
  }
  return 0;
}
