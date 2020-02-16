#include <iostream>

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
    a = b;
    return true;
  }
  return false;
}

const long long INF {1LL << 60};
const int MAX_N {110};
const int MAX_V {100100};
int N;
long long W;
long long weights [MAX_N];
long long values [MAX_N];
long long dp[MAX_N][MAX_V];

int main()
{
  std::cin >> N >> W;
  for ( int i = 0; i < N; i++ ) std::cin >> weights[i] >> values[i];
  
  // DP table
  for ( int i = 0; i < MAX_N; i++ ) {
    for ( int j = 0; j < MAX_V; j++ ) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
      if ( sum_v - values[i] >= 0 ) {
        chmin(dp[i+1][sum_v], dp[i][sum_v - values[i]] + weights[i]);
      }
      chmin(dp[i+1][sum_v], dp[i][sum_v]);
    }
  }

  long long ans {0};
  for ( int sum_v = 0; sum_v < MAX_V; sum_v++ ) {
    if ( dp[N][sum_v] <= W ) {
      ans = sum_v;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
