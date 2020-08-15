#include <iostream>
using namespace std;

const int MAX = 225;

bool solve(int A[], int n, int m, int i) {
  if (m == 0) return true;
  if (i >= n) {
    return false;
  }
  return solve(A, n, m, i+1) || solve(A, n, m - A[i], i+1);
}

int main() {
  // input
  int n, q;
  int A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    if (solve(A, n, m, 0)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
