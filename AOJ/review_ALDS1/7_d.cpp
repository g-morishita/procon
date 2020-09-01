#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
int idx = 0;
vector<int> postorder;


void reconstructTree(int inorder[], int preorder[], int left, int right) {
  if (right <= left) return;
  int c = preorder[idx++];
  int m {0};

  for (m = left; m < right; m++) {
    if (c == inorder[m]) break;
  }

  reconstructTree(inorder, preorder, left, m);
  reconstructTree(inorder, preorder, m+1, right);
  postorder.push_back(c);
}

int main() {
  int n;
  int preoder[MAX];
  int inorder[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> preoder[i];
  for (int i = 0; i < n; i++) cin >> inorder[i];

  reconstructTree(inorder, preoder, 0, n);
  for (int i  = 0; i < n; i++) {
    if (i) cout << " ";
    cout << postorder.at(i);
  }
  cout << endl;

  return 0;
}
