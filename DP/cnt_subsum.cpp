#include <iostream>
#include <cstring>

const int MOD = 1000000009;

int main(void) 
{
  int n;
  std::cin >> n;
  int a[n];
  for ( int i = 0; i < n; i++ ) std::cin >> a[i];
  int A;
  std::cin >> A;

  // DP table 
  int dp[n+1][A+1];
  std::memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j <= A; j++ ) {
      if ( a[i] <= j ) {
        (dp[i+1][j] = dp[i][j] + dp[i][j - a[i]]) %= MOD;
      } else {
        (dp[i+1][j] = dp[i][j]) %= MOD;
      }
    }
  }


  // for ( int i = 0; i <= n; i++ ) {
  //    for ( int j = 0; j <= A; j++ ) {
  //      std::cout << "dp["<< i << "]" << "[" << j << "] " << dp[i][j] << std::endl;
  //    }
  //  }
  std::cout << dp[n][A] << std::endl;
  return 0;
}
