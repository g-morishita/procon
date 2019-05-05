#include <iostream>
#include <cstring>
#include <algorithm>

const int INF = 1<<29;

int main(void)
{
  // input
  int n;
  std::cin >> n;
  int a[n];
  for ( int i = 0; i < n; i++ ) std::cin >> a[i];
  int A;
  std::cin >> A;

  // DP table
  int dp[n+1][A+1];
  for ( int i = 0; i <= n; i++ ) {
    for ( int j = 0; j <= A; j++ ) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j <= A; j++ ) {
      if ( j >= a[i] ) {
        dp[i+1][j] = std::min(dp[i][j-a[i]]+1, dp[i][j]);
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
  }

  if ( dp[n][A] < INF ) std::cout << dp[n][A] << std::endl;
  else std::cout << -1 << std::endl;
  return 0;
}
