#include <iostream>
#include <cstring>

int main(void) {
  // input
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int A;
  std::cin >> A;

  // DP table
  bool dp[n+1][A+1];

  std::memset(dp, 0, sizeof(dp));
  dp[0][0] = true;

  for ( int i = 0; i <= n; i++ ) {
    for ( int j = 1; j <= A; j++ ) {
      if ( a[i] <= j ) {
        dp[i+1][j] = dp[i][j - a[i]] | dp[i][j];    
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
  }
  // debug
  // for ( int i = 0; i <= n; i++ ) {
  //   for ( int j = 0; j <= A; j++ ) {
  //     std::cout << "dp["<< i << "]" << "[" << j << "] " << dp[i][j] << std::endl;
  //   }
  // }

  if ( dp[n][A] ) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}
