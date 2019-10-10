#include <iostream>
#include <algorithm>
#include <vector>

template<class T> inline bool chmax(T& a, T b) {
  if ( a < b ) {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 60;
const int MAX_INDEX = 100010;
long long dp[MAX_INDEX][3];

int main()
{
  int N; 
  std::cin >> N;
  long long a[MAX_INDEX][3];
  for ( int i = 0; i < MAX_INDEX; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      std::cin >> a[i][j];
    }
  }
  for ( int i = 0; i < N; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      for ( int k = 0; k < 3; k++ ) {
        std::cin >> N;
        if ( j == k ) continue;
        chmax(dp[i+1][k], dp[i][j] + a[i][k]);
      }
    }
  }
  long long res = 0;
  for ( int i = 0; i < 3; i++ ) {
    chmax(res, dp[N][i]);
  }
  std::cout << res << std::endl;
  return 0;
}
