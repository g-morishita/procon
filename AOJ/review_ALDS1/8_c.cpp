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
    z->parent = y;
    if (y->key < z->key) {
      y->right = z;
    } else {
      y->left = z;
    }
  }
}

BinaryNode* find(int key, BinaryNode *u) {
  while (u != NIL) {
    if (u->key == key) {
      return u;
    } else if (u->key > key) {
      u = u->left;
    } else {
      u = u->right;
    }
  }

  return NIL;
}

void deleteNode(int key) {
  BinaryNode* u = find(key, root);
  if (u == NIL) return;
  // a target node has no child 
  if ((u->left == NIL) && (u->right == NIL)) {
    if (u == root) {
      root = NIL;
      free(u);
      return;
    }

    if (u->parent == NIL) cerr << "u->parent is NIL somehow" << endl;
    if (u->parent->left == u) {
      u->parent->left = NIL;
    } else {
      u->parent->right = NIL;
    }

  } else if ((u->left != NIL) && (u->right != NIL)) { // a target node has two children
    // find a minimum node among a target node's children
    BinaryNode *maximum_child = u->right;
    while (maximum_child->left != NIL) {
      maximum_child = maximum_child->left;
    }

    // if the child does not have a left child
    if (maximum_child->right == NIL) {
      u->key = maximum_child->key;
      if (maximum_child->parent == u) {
        maximum_child->parent->right = NIL;
      } else {
        maximum_child->parent->left = NIL;
      }
    } else { // if the child has a left child
      u->key = maximum_child->key;
      if (maximum_child->parent == u) {
        maximum_child->parent->right = maximum_child->left;
      } else {
        maximum_child->parent->left = maximum_child->right;
      }
      maximum_child->right->parent = maximum_child->parent;
    }
  } else { // a target has only one child
    if (u == root) {
      if (u->left != NIL) {
        u->left->parent = NIL;
        root = u->left;
        free(u);
        return;
      } else {
        u->right->parent = NIL;
        root = u->right;
        free(u);
        return;
      }
    }

    if (u->left != NIL) {
      u->left->parent = u->parent;
      if (u->parent->left == u) {
        u->parent->left = u->left;
      } else {
        u->parent->right = u->left;
      }
    } else {
      u->right->parent = u->parent;
      if (u->parent->left == u) {
        u->parent->left = u->right;
      } else {
        u->parent->right = u->right;
      }
    }
  }
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
      if (find(key, root) != NIL) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else if (s == "delete") {
      cin >> key;
      deleteNode(key);
    }
  }
  return 0;
}
