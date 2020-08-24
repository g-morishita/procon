#include <iostream>
#include <string>
using namespace std;

const int NIL = -1;
const int MAX = 50;

struct BinaryTreeNode {
  int parent {NIL};
  int left_child {NIL};
  int right_child {NIL};
  int depth {NIL};
  int sibling {NIL};
  int height {NIL};
};

void setDepth(int node_id, int depth, BinaryTreeNode tree[]) {
  if (node_id == NIL) return;
  tree[node_id].depth = depth;
  int left_child = tree[node_id].left_child;
  int right_child = tree[node_id].right_child;
  setDepth(left_child, depth + 1, tree);
  setDepth(right_child, depth + 1, tree);
}

int getSibling(int node_id, BinaryTreeNode tree[]) {
  int parent = tree[node_id].parent;
  if (parent == NIL) return NIL;

  if (tree[parent].left_child == node_id) {
    return tree[parent].right_child;
  } else {
    return tree[parent].left_child;
  }
}

int setHeight(int node_id, BinaryTreeNode tree[]) {
  if (tree[node_id].left_child == NIL && tree[node_id].right_child == NIL) return tree[node_id].height = 0;
  int h_left = setHeight(tree[node_id].left_child, tree);
  int h_right = setHeight(tree[node_id].right_child, tree);
  return tree[node_id].height = (h_left > h_right ? h_left : h_right) + 1;
}

int findRoot(BinaryTreeNode tree[], int n) {
  for (int i = 0; i < n; i++) {
    if (tree[i].parent == NIL) {
      return i;
    }
  }
  return NIL;
}

string getKind(int node_id, BinaryTreeNode tree[]) {
  if (tree[node_id].parent == NIL) return "root";
  if (tree[node_id].left_child == NIL && tree[node_id].right_child == NIL) return "leaf";
  return "internal node";
}

int getDegree(int node_id, BinaryTreeNode tree[]) {
  int degree {0};
  if (tree[node_id].left_child != NIL) degree++;
  if (tree[node_id].right_child != NIL) degree++;
  return degree;
}

int main() {
  int n, id, left_child, right_child;
  BinaryTreeNode tree[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> id >> left_child >> right_child;
    tree[id].left_child = left_child;
    tree[id].right_child = right_child;
    if (left_child != NIL) {
      tree[left_child].sibling = right_child;
      tree[left_child].parent = id;
    }
    if (right_child != NIL) {
      tree[right_child].sibling = left_child;
      tree[right_child].parent = id;
    }
  }
  int root = findRoot(tree, n);

  setDepth(root, 0, tree);
  setHeight(root, tree);

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << tree[i].parent << ", sibling = " << tree[i].sibling << ", degree = " << getDegree(i, tree) << ", depth = " << tree[i].depth << ", height = "<< tree[i].height << ", " << getKind(i, tree) << endl;
  }

  return 0;
}
