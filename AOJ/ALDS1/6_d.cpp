#include <iostream>
#include <algorithm>
using namespace std;

const int VMAX = 10000 + 1;
const int MAX = 1000;
int s;
int W[MAX];
int B[MAX], T[VMAX];

int solve(int n) {
  int ans {0};
  bool V[MAX];

  for (int i = 0; i < n; i++) {
    B[i] = W[i];
    V[i] = false;
  }

  sort(B, B+n);
  for (int i = 0; i < n; i++) T[B[i]] = i;

  for (int i = 0; i < n; i++) {
    int currrent_index = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    if ( V[i] ) continue;
    while (true) {
      V[currrent_index] = true;
      an++;
      int v = W[currrent_index];
      m = min(m, v);
      S += v;
      currrent_index = T[v];
      if (V[currrent_index]) break;
    }
    ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
  }
  return ans;
}

int main() {
  int n {0};
  cin >> n;
  s = VMAX;
  for (int i = 0; i < n; i++) {
    cin >> W[i];
    s = min(s, W[i]);
  }
  int ans = solve(n);
  cout << ans << endl;
  return 0;
}
