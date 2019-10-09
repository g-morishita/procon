#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
  int n;
  std::cin >> n;
  while (true) {
    std::vector<long long> dp(40);
    dp[0] = 1;
    for ( int now = 0; now < n; now++ ) {
      for ( int next = now + 1; next <= std::min(n, now + 3); next++ ) {
        dp[next] += dp[now];
      }
    }
    std::cout << (dp[n] + 3650 - 1) / 3650 << std::endl;
    std::cin >> n;
    if ( n == 0 ) break;
  }
  return 0;
}
