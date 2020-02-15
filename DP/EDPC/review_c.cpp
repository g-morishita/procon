#include <iostream>
#include <vector>
#include <algorithm>

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main()
{
  int N {0};
  std::cin >> N;
  int a[N+1][3] {0};
  for (int i = 1; i <= N; i++) {
    std::cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  long long dp[N+1][3] {0};
  for ( int i = 0; i <= N; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      for ( int k = 0; k < 3; k++ ) {
        if ( j == k ) continue;
        chmax(dp[i+1][j], dp[i][k] + a[i+1][j]);
      }
    }
  }
  long long ans {0};
  for ( int i = 0; i < 3; i++ ) {
    if ( ans < dp[N][i] ) ans = dp[N][i];
  }
  std::cout << ans << std::endl;
  return 0;
}
