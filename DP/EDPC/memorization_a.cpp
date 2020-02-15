#include <iostream>
#include <vector>
#include <cstdlib>

template<class T> inline bool chmin(T& a, T b) 
{
  if ( a > b ) {
    a = b;
    return true;
  } else {
    return false;
  }
}

template<class T> inline bool chmax(T& a, T b) 
{
  if ( a < b ) {
    a = b;
    return true;
  } else {
    return false;
  }
}

const int max_index {100010};
const long long INF {1LL << 60};
long long dp[max_index];
long long h[max_index];

long long rec(int i)
{
  if (dp[i] < INF) return dp[i];

  if (i == 0) return 0;

  long long res = INF;
  chmin(res, rec(i-1) + std::abs(h[i] - h[i -1]));
  if (i > 1) chmin(res, rec(i-2) + std::abs(h[i] - h[i-2]));

  return dp[i] = res;
}

int main()
{
  // input
  int N {0};
  std::cin >> N;
  for (int i = 0; i < N; i++) std::cin >> h[i];
  for (int i = 0; i < N; i++) dp[i] = INF;

  std::cout << rec(N-1) << std::endl;
  return 0;
}
