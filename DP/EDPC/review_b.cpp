#include <iostream>
#include <cstdlib>
#include <vector>

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

const long long INF {1LL << 60};
const int max_index {110000};

int main()
{
  int n {0};
  int k {0};
  std::cin >> n >> k;
  long long h [max_index] {0};
  for (int i = 0; i < n; i++) {
    std::cin >> h[i];
  }
  
  long long dp [max_index] {0};
  for (int i = 0; i < max_index; i++) {
    dp[i] = INF;
  }
  dp[0] = 0;

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 1; j <= k; j++ ) {
      chmin(dp[i+j], dp[i] + std::abs(h[i] - h[i+j]));
    }
  }
  std::cout << dp[n-1] << std::endl;
  return 0;
}
