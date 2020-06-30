#include <iostream>
using namespace std;

int n, A[50];

bool can_solve(int i, int m) {
  if (m == 0) return 1;
  if (i >= n) return 0;
  int res = can_solve(i+1, m) || can_solve(i+1, m - A[i]);
  return res;
}

int main() {
  int q, M, i;
  cin >> n;

  for(i = 0; i < n; i++) {
    cin >> A[i];
  }
  cin >> q;

  for (i = 0; i < q; i++) {
    cin >> M;
    if (can_solve(0, M)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
