#include <iostream>
using namespace std;

const int MAX = 10005;

bool search(int A[], int n, int key) {
  A[n] = key;
  int i {0};
  while (A[i] != key) i++;
  return i != n;
}

int main() {
  int S[MAX];
  int T[MAX];
  int n {0}, q {0}, cnt {0};
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> T[i];

  for (int i = 0; i < q; i++) {
    if (search(S, n, T[i])) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
