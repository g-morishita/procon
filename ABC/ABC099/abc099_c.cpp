#include <iostream>
#include <vector>
#include <cmath>

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 60;
const long MAX_NUM = 100010;
const int MAX_INDEX = 7;

int main()
{
  int N;
  std::cin >> N;
  std::vector<long long> dp(MAX_NUM, INF);
  dp[0] = 0;
  for ( int now = 0; now <= N; now++ ) {
    chmin(dp[now + 1], dp[now] + 1);
    for ( int i = 1; i <= MAX_INDEX; i++ ) {
      if (now + std::pow(6, i) <= MAX_NUM) chmin(dp[now + std::pow(6, i)], dp[now] + 1);
      if (now + std::pow(9, i) <= MAX_NUM) chmin(dp[now + std::pow(9, i)], dp[now] + 1);
    }
  }
  std::cout << dp[N] << std::endl;
  return 0;
}
