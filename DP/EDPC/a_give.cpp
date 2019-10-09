#include <iostream>
#include <vector>
#include <cstdlib>

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
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

const long long INF = 1LL << 60;

int main()
{
  // input and DP table
  int N; std::cin >> N;
  long long h[100010];
  long long dp[100010];

  for ( int i = 0; i < N; i++ ) {
    std::cin >> h[i];
  }

  // initilize the DP table
  for ( int i = 0; i < 100010; i++ ) {
    dp[i] = INF;
  }
  
  dp[0] = 0;

  // update the DP table
  for ( int i = 0; i < N; i++ ) {
    chmin(dp[i+1], dp[i] + std::abs(h[i] - h[i+1]));
    chmin(dp[i+2], dp[i] + std::abs(h[i] - h[i+2]));
  }

  // output the answer
  std::cout << dp[N-1] << std::endl;
}
