#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

const long long INF = 1LL << 60;
const int MAX_NUM = 100010;

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> h(N);
  for ( int i = 0; i < N; i++ ) std::cin >> h[i];
  std::vector<long long> dp(MAX_NUM, INF);
  dp[0] = 0;
  for ( int now = 0; now < N; now++ ) {
    for ( int next = now + 1; next <= std::min(N, now + K); next++ ) {
      chmin(dp[next], dp[now] + std::abs(h[now] - h[next]));
    }
  }
  std::cout << dp[N-1] << std::endl;
  return 0;
}
