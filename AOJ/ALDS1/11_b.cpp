#include <iostream>
using namespace std;

const int MAX = 105;
int color[MAX];
int am[MAX][MAX];
int d[MAX];
int f[MAX];
int t;


void dfs(int u) {
  color[u] = 1;
  d[u] = ++t;
  for (int i = 0; i < MAX; i++) {
    if (am[u][i] == 0) continue;
    if (color[i] == 0) {
      dfs(i);
    }
  }
  color[u] = 2;
  f[u] = ++t;
}

int main() {
  int n, u, k;
  int tmp;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> tmp;
      am[u-1][tmp-1] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      dfs(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << (i+1) << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}
