#include <iostream>

int main(void)
{
  int n;
  std::cin >> n;
  int a[n];
  for ( int i = 0; i < n; i++ ) std::cin >> a[i];
  int dp[n+1] = {};

  for ( int i = 0; i < n; i++ ) {
    if ( a[i] > 0 ) {
      dp[i+1] = dp[i] + a[i];
    } else {
      dp[i+1] = dp[i];
    }
  }
}
