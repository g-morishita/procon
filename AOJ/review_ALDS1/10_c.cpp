#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 1005;

int solve(string s, string t) {
  int dp[MAX_LENGTH][MAX_LENGTH];
  int m, n;
  int maxl = 0;
  n = s.size();
  m = t.size();
  s = ' ' + s;
  t = ' ' + t;

  for (int i = 1; i <= n; i++) dp[i][0] = 0;
  for (int i = 1; i <= m; i++) dp[0][i] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
      maxl = max(maxl, dp[i][j]);
    }
  }
  return maxl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
  }
}
