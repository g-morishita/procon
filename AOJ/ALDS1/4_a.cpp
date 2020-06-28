#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      return i;
    }
  }
  return -1;
}

const int MAX = 10005;

int n, q;
int S[MAX];
int T[MAX];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> T[i];

  int ans {0};
  for (int i = 0; i < q; i++) {
    if (linearSearch(S, n, T[i]) != -1) {
      ans++;
    }
  }
  cout << ans << endl;
}
