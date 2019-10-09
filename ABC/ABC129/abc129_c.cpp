#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

const long long MOD = 1e9 + 7;

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<int> oks(N+1, true);
  for ( int i = 0; i < M; i++ ) {
    int a;
    std::cin >> a;
    oks[a] = false;
  }

  std::vector<long long> dp(N+1);
  dp[0] = 1;

  for ( int now = 0; now < N; now++ ) {
    for ( int next = now + 1; next <= std::min(N, now + 2); next++ ) {
      if (oks[next]) {
        dp[next] += dp[now];
        dp[next] %= MOD;
      }
    }
  }
  std::cout << dp[N] << std::endl;
  return 0;
}
