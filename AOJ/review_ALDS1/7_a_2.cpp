#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int NIL = -1;
const int MAX = 100000;

struct Node {
  int parent {NIL};
  int left_child {NIL};
  int right_sibling {NIL};
  int depth {NIL};
};

void setDepth(int node_id, int depth, Node tree[]) {
  tree[node_id].depth = depth;
  if (tree[node_id].right_sibling != NIL) {
    setDepth(tree[node_id].right_sibling, depth, tree);
  }

  if (tree[node_id].left_child != NIL) {
    setDepth(tree[node_id].left_child, depth + 1, tree);
  }
}

int findRoot(Node tree[], int n) {
  int root {0};
  for (int i = 0; i < n; i++) {
    root = i;
    if (tree[i].parent == NIL) return root;
  }
  return root;
}

vector<int> getChildren(int id, Node tree[]) {
  vector<int> children_list;
  int child_node = tree[id].left_child;
  while (child_node != NIL) {
    children_list.push_back(child_node);
    child_node = tree[child_node].right_sibling;
  }

  return children_list;
}

string getKind(int id, Node tree[]) {
  if (tree[id].parent == NIL) return "root";
  if (tree[id].left_child == NIL) return "leaf";
  return "internal node";
}

void print(Node tree[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth << ", " << getKind(i, tree) << ", [";
    vector<int> children_list = getChildren(i, tree);
    for (int i = 0; i < children_list.size(); i++) {
      cout << children_list.at(i);
      if (i != children_list.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }
}

int main() {
  int n, id, k, child, prev_child;
  Node tree[MAX];
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> id >> k;
    for (int j = 0; j < k; j++) {
      cin >> child;
      if (j == 0) {
        tree[id].left_child = child;
      } else {
        tree[prev_child].right_sibling = child;
      }
      prev_child = child;
      tree[child].parent = id;
    }
  }

  int root = findRoot(tree, n);
  setDepth(root, 0, tree);

  print(tree, n);
}
