#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int x[N];
  int y[N];

  for ( int i = 0; i < N; i++ ) std::cin >> x[i] >> y[i];

  int max = 0;
  for ( int i = 0; i < N; i++ ) {
    for ( int j = i + 1; j < N; j++ ) {
      int dis = std::pow(x[i] - x[j], 2) + std::pow(y[i] - y[j], 2);
      if ( dis > max ) {
        max = dis;
      }
    }
  }
  std::cout << std::sqrt(max) << std::endl;
  return 0;
}
