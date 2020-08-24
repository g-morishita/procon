#include <iostream>
using namespace std;

const int NIL = -1;
const int MAX = 30;

struct BinaryTree {
  int left {NIL};
  int right {NIL};
  int parent {NIL};
};

void print_preorder(BinaryTree T[], int n, int root_id) {
  if (root_id == NIL) return;
  cout << " " << root_id;
  print_preorder(T, n, T[root_id].left);
  print_preorder(T, n, T[root_id].right);
}

void print_inorder(BinaryTree T[], int n, int root_id) {
  if (root_id == NIL) return;
  print_inorder(T, n, T[root_id].left);
  cout << " " << root_id;
  print_inorder(T, n, T[root_id].right);
}

void print_postorder(BinaryTree T[], int n, int root_id) {
  if (root_id == NIL) return;
  print_postorder(T, n, T[root_id].left);
  print_postorder(T, n, T[root_id].right);
  cout << " "  << root_id;
}

int findRoot(BinaryTree T[], int n) {
  int root {0};
  for (root = 0; root < n; root++) {
    if (T[root].parent == NIL) break;
  }
  return root;
}

int main() {
  int n;
  BinaryTree T[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) {
    int id, left, right;
    cin >> id >> left >> right;

    if (left != NIL) {
      T[id].left = left;
      T[left].parent = id;
    }

    if (right != NIL) {
      T[id].right = right;
      T[right].parent = id;
    }
  }

  int root = findRoot(T, n);

  cout << "Preorder" << endl;
  print_preorder(T, n, root); cout << endl;

  cout << "Inorder" << endl;
  print_inorder(T, n, root);
  cout << endl;

  cout << "Postorder" << endl;
  print_postorder(T, n, root);
  cout << endl;

  return 0;
}
