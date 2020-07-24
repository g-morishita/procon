#include <iostream>
#include <string>
using namespace std;

const int N = 1000;

int lcs(string a, string b) {
  int C[N+1][N+1];
  int n = a.size();
  int m = b.size();
  for (int i = 0; i <= n; i++) C[i][0] = 0;
  for (int i = 0; i <= m; i++) C[0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i-1] == b[j-1]) {
        C[i][j] = C[i-1][j-1] + 1;
      } else {
        C[i][j] = C[i][j-1] > C[i-1][j] ? C[i][j-1] : C[i-1][j];
      }
    }
  }
  return C[n][m];
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string X, Y;
    cin >> X >> Y;
    cout << lcs(X, Y) << endl;
  }
  return 0;
}
