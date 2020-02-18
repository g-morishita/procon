#include <iostream>

template<class T> inline bool chmax(T& a, T b) {
  if ( a < b ) {
    a = b;
    return true;
  }
  return false;
}
const int MAX_N {110};
const int MAX_W {100010};
long long dp[MAX_N][MAX_W] {{0}};
int N;
long long W;
long long weight [MAX_N] {0};
long long value [MAX_N] {0};

int main()
{
  std::cin >> N >> W;
  for ( int i = 0; i < N; i++ ) {
    std::cin >> weight[i] >> value[i];
  }

  for (int n = 0; n < N; n++) {
    for (int w = 0; w <= W; w++) {
      if (w - weight[n] >= 0) {
        chmax(dp[n+1][w], dp[n][w - weight[n]] + value[n]);
      }
      chmax(dp[n+1][w], dp[n][w]);
    }
  }

  std::cout << dp[N][W] << std::endl;
  return 0;
}
