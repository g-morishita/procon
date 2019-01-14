#include <iostream>
#include <cmath>

int main()
{
  int N, T, A;
  std::cin >> N >> T >> A;
  int H[N];
  double ans = std::pow(10, 5);
  int pos;
  for ( int i = 0; i < N; i++ ) {
    std::cin >> H[i];
    double tmp = std::abs(A - T + H[i] * 0.006);
    if ( ans > tmp ) {
      ans = tmp;
      pos = i;
    }
  }

  std::cout << pos + 1 << std::endl;
  return 0;
}
