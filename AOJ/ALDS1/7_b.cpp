#include <iostream>
using namespace std;

const int NIL = -1;
const int MAX = 100000;
int root;

struct Node { 
  int id;
  int parent;
  int left;
  int right;
};

Node T[MAX];
int D[MAX];
int H[MAX];

void setDepth(int u, int p) {
  if (u == NIL) return;
  D[u] = p;
  if (T[u].left != NIL) setDepth(T[u].left, p + 1);
  if (T[u].right != NIL) setDepth(T[u].right, p + 1);
}

int getHeight(int u) {
  int h1 {0}, h2 {0};
  if (T[u].left != NIL) {
    h1 = getHeight(T[u].left) + 1;
  }
  if (T[u].right != NIL) {
    h2 = getHeight(T[u].right) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u) {
  if (T[u].parent == NIL) return NIL;
  if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
    return T[T[u].parent].left;
  }
  if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
    return T[T[u].parent].right;
  }
  return NIL;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    T[i].id = T[i].left = T[i].right = T[i].parent = NIL;
  }

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    cin >> T[v].left >> T[v].right;
    if (T[v].left != NIL) {
      T[T[v].left].parent = v;
    }
    if (T[v].right != NIL) {
      T[T[v].right].parent = v;
    }
  }

  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      root = i;
      break;
    }
  }

  setDepth(root, 0);
  getHeight(root);

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "sibling = " << getSibling(i) << ", ";
    int deg {0};
    if (T[i].left != NIL) deg++;
    if (T[i].right != NIL) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[i] << ", ";
    cout << "height = " << H[i] << ", ";
    if (T[i].parent == NIL)  {
      cout << "root";
    } else if (T[i].left == NIL && T[i].right == NIL) {
      cout << "leaf"; 
    } else {
      cout << "internal node";
    }
    cout << endl;
  }
}
