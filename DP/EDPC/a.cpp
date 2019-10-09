#include <iostream>
#include <vector>
#include <cstdlib>

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> inline bool chmax(T& a, T b) {
  if ( a < b ) {
    a = b;
    return true;
  }
  return false;
}

// define a positive infinity value as INF
const long long INF = 1LL << 60;

int main()
{
  // DP table
  long long dp[100010];

  // initilize DP table with INF
  for ( int i = 0; i < 100010; i++ ) dp[i] = INF;

  // initilize the cost of the first position with 0 
  dp[0] = 0;

  // input
  int N; std::cin >> N;
  long long h[100010];
  for ( int i = 0; i < N; i++ ) std::cin >> h[i];

  dp[1] = dp[0] + std::abs(h[1] - h[0]);
  for ( int i = 2; i < N; i++ ) {
    chmin(dp[i], dp[i-1] + std::abs(h[i] - h[i-1]));
    chmin(dp[i], dp[i-2] + std::abs(h[i] - h[i-2]));
  }
  for ( int i = 0; i < N; i++ ) std::cerr << dp[i] << std::endl;

  std::cout << dp[N-1] << std::endl;
  return 0;
}
