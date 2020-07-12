#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int NIL = -1;

struct Node {
  int parent;
  int left;
  int right;
};

vector<int> PRE, IN, POST;
int pos;

int find_root_idx(int A[], int n, int r) {
  int root_idx {NIL};
  for (root_idx = 0; root_idx < n; root_idx++) {
    if (A[root_idx] == r) {
      break;
    }
  }
  return root_idx;
}

void reconstruction(int left, int right) {
  if (left >= right) return;
  int root = PRE[pos++];
  int mid = distance(IN.begin(), find(IN.begin(), IN.end(), root));
  reconstruction(left, mid);
  reconstruction(mid + 1, right);
  POST.push_back(root);
}


int main() {
  int n, k;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> k;
    PRE.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    cin >> k;
    IN.push_back(k);
  }

  reconstruction(0, PRE.size());
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << POST.at(i);
  }
  cout << endl;
  return 0;
}
