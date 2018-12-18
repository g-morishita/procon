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

  int pos = 0;
  int min = std::abs(A+H[0] * 0.006);
  for ( int i = 1; i < N; i++ ) {
    int dis = std::abs(A + H[i] * 0.006);
    if ( dis < min ) {
      min = dis;
      pos = i;
    }
  }

  std::cout << pos + 1 << std::endl;
  return 0;
}
