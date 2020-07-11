#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100005;
const int NIL = -1;
struct Node {
  int parent {0};
  int left_child {0};
  int right_sibling {0};
};

struct Node T[MAX];
int D[MAX];

vector<int> split(string str) {
  vector<int> v;
  string s = "";

  for (char c: str) {
    if (c == ' ') {
      v.push_back(stoi(s));
      s = "";
    } else {
      s += c;
    }
  }
  return v;
}

void setDepth(int u, int p) {
  D[u] = p;
  if (T[u].right_sibling != NIL) setDepth(T[u].right_sibling, p);
  if (T[u].left_child != NIL) setDepth(T[u].left_child, p + 1);
}

void printChildren(int u) {
  cout << "[";
  int child = T[u].left_child;
  if (child != NIL) {
    cout << child;
    while ((child = T[child].right_sibling) != NIL) {
      cout << ", " << child;
    }
  }
  cout << "]";
}

void printKind(int u) {
  if (T[u].parent == NIL) {
    cout << "root";
  } else if (T[u].left_child == NIL) {
    cout << "leaf";
  } else {
    cout << "internal node";
  }
}

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " <<  D[u] << ", ";
  printKind(u);
  cout << ", ";
  printChildren(u);
  cout << endl;
}

int main() {
  int n, previous_node {0};
  cin >> n;
  int id, k;

  for (int i = 0; i < n; i++) {
    T[i].parent = NIL;
    T[i].left_child = NIL;
    T[i].right_sibling = NIL;
  }

  T[0].parent = NIL;
  for (int i = 0; i < n; i++) {
    cin >> id >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      if (j == 0) {
        T[id].left_child = c;
      } else {
        T[previous_node].right_sibling = c;
      }
      previous_node = c;
      T[c].parent = id;
    }
  }
  int r;
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      r = i;
    }
  }
  setDepth(r, 0);
  for (int i = 0; i < n; i++) {
    print(i);
  }
}
