#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int T, A;
  int H[N];
  std::cin >> T >> A;
  for ( int i = 0; i < N; i++ ) std::cin >> H[i];

  int pos = 1;
  double min = std::abs(A - T + H[0] * 0.006);
  for ( int i = 1; i < N; i++ ) {
    double dis = std::abs(A - T + H[i] * 0.006);
    if ( dis < min ) {
      min = dis;
      pos = i + 1;
    }
  }

  std::cout << pos << std::endl;
  return 0;
}
