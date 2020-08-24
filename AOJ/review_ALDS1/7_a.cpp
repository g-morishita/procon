#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100000;

struct Node {
  int key {-1};
  int parent {-1};
  vector<int> children;
};

string get_kind(Node node) {
  if (node.parent == -1) return "root";
  if (!node.children.size()) return "leaf";
  return "internal node";
}

int get_depth(Node target, Node tree[]) {
  int depth {0};
  while (target.parent != -1) {
    depth++;
    target = tree[target.parent];
  }
  return depth;
}

string get_children(Node node) {
  string children_list ("");
  children_list += "[";
  for (int i = 0; i < node.children.size(); i++) {
    children_list += to_string(node.children.at(i));
    if (i != node.children.size() - 1) children_list += ", ";
  }
  children_list += "]";
  return children_list;
}

int main() {
  // input the given tree
  Node tree[MAX];
  int n, k, id, child;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> id >> k;
    for (int j = 0; j < k; j++) {
      cin >> child;
      tree[id].children.push_back(child);
      tree[child].parent = id;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << get_depth(tree[i], tree) << ", " << get_kind(tree[i]) << ", " << get_children(tree[i]) << endl;
  }
}
