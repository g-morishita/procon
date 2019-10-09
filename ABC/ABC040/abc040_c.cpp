#include <iostream>
#include <vector>
#include <cstdlib>

long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  long long dp[100010];
  for ( int i = 0; i < 100010; i++ ) dp[i] = INF;
  int N; std::cin >> N;
  long long h[N];
  for ( int i = 0; i < N; i++ ) std::cin >> h[i];

  dp[0] = 0;
  for ( int i = 1; i < N; i++ ) {
    chmin(dp[i], dp[i-1] + std::abs(h[i] - h[i-1]));
    if ( i > 1 ) chmin(dp[i], dp[i-2] + std::abs(h[i] - h[i-2]));
  }

  std::cout << dp[N-1] << std::endl;
  return 0;
}
