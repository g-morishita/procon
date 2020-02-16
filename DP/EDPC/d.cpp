#include <iostream>
#include <vector>

template<class T> inline bool chmax(T& a, T b) {
  if ( a < b ) {
    a = b;
    return true;
  }
  return false;
}
long long dp[110][100100];

int main()
{
  int N {0};
  long long W {0};
  std::cin >> N >> W;
  long long weight_value_table[N][2];
  for ( int i = 0; i < N; i++ ) {
    for ( int j = 0; j < 2; j++ ) {
      std::cin >> weight_value_table[i][j];
    }
  }

  for ( int i = 0; i < N; i++ ) {
    for ( int sum_w = 0; sum_w <= W; sum_w++ ) {
      if ( sum_w - weight_value_table[i][0] >= 0 ) {
        chmax(dp[i+1][sum_w], dp[i][sum_w - weight_value_table[i][0]] + weight_value_table[i][1]);
      } 
      chmax(dp[i+1][sum_w], dp[i][sum_w]);
    }
  }
  std::cout << dp[N][W] << std::endl;
  return 0;
}
