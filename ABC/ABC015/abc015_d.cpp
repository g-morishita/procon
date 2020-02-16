#include <iostream>
template<class T> inline bool chmax(T& a, T b) {
  if ( a < b ) {
    a = b;
    return true;
  }
  return false;
}
const int MAX_W {10100};
const int MAX_N {60};
const int MAX_K {60};
int W, N, K;
int a [MAX_N] {0};
int b [MAX_N] {0};
long long dp [MAX_N][MAX_W][MAX_K] {0};

int main()
{
  std::cin >> W >> N >> K;
  for ( int i = 0; i < N; i++ ) std::cin >> a[i] >> b[i];

  for ( int i = 0; i < N; i++ ) {
    for ( int j = 0; j < MAX_W; j++ ) {
      for ( int k = 1; k < MAX_K; k++ ) {
        if ( k == 1 && (j - a[i] >= 0)) {
          dp[i+1][j][k] = b[i];
        }
        for ( int l = 1; l < k; l++ ) {
          if (j - a[i] >= 0) {
            chmax(dp[i+1][j][k], dp[i][j - a[i]][l] + b[i]);
          }
        }
        chmax(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }

  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j <= W; j++) {
  //     for (int k = 0; k <= K; k++) {
  //       std::cerr << "dp[" << i << "][" << j << "][" << k << "]" << "=" << dp[i][j][k] << std::endl;
  //     }
  //   }
  // }

  std::cout << dp[N][W][K] << std::endl;
  return 0;
}
