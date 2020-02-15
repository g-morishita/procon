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
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

const long long INF {1LL << 60};
const int max_index {100010};


int main()
{
  // input 
  long long h [max_index];
  int n {0};
  std::cin >> n;
  for ( int i = 0; i < n; i++ ) {
    std::cin >> h[i];
  }

  // initialize dp table
  long long dp [max_index];
  for ( int i = 0; i < n; i++ ) {
    dp[i] = INF;
  }
  dp[0] = 0;

  for ( int i = 1; i < n; i++ ) {
    chmin(dp[i], dp[i-1] + std::abs(h[i] - h[i - 1]));
    if ( i > 1 ) {
      chmin(dp[i], dp[i-2] + std::abs(h[i] - h[i-2]));
    }
  }
  
  // answer
  std::cout << dp[n-1] << std::endl;
  return 0;
}
