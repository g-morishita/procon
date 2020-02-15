#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

template<class T> inline bool chmin(T& a, T b) {
  if ( a > b ) {
    a = b;
    return true;
  }
  return false;
}

const int ONE {1};
const int SIX {6};
const int NINE {9};
const int max_index {100010};
const int K {7}; // > log_6(100000)
const long long INF {1LL << 60};
int N;
long long dp[max_index];

int check(int index, int num) {
  for ( int k = 1; k < K; k++ ) {
    int res {index - static_cast<int>(std::pow(num, k))};
    if ( res >= 0 ) {
      chmin(dp[index], dp[res] + 1);
    } else {
      break;
    }
  }
  return 0;
}

int main()
{
  std::cin >> N;
  for ( int i = 0; i < max_index; i++ ) dp[i] = INF;
  dp[0] = 0;
  for ( int i = 1; i <= N; i++ ) {
    check(i, SIX);
    check(i, NINE);
    chmin(dp[i], dp[i - ONE] + 1);
  }

  // for (int i = 0; i <= N; i++) std::cerr << dp[i] << std::endl;
  std::cout << dp[N] << std::endl;
  return 0;
}
