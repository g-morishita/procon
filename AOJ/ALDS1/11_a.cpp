#include <iostream>
using namespace std;

const int MAX = 105;
int m[MAX][MAX];

int main() {
  int n, u, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u][v] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j != 1) cout << " ";
      cout << m[i][j];
    }
    cout << endl;
  }
  return 0;
}
