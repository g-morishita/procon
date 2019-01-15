#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int x[N];
  int y[N];
  for ( int i = 0; i < N; i++ ) std::cin >> x[i] >> y[i];
  long int max = (x[0]-x[1]) * (x[0]-x[1]) + (y[0]-y[1]) + (y[0]-y[1]);

  for ( int i = 0; i < N; i++ ) {
    for ( int j = i+1; j < N; j++ ) {
      long dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      if ( max < dist ) max = dist;
    }
  }

  double d = std::sqrt(max);
  std::cout << d << std::endl;
  return 0;
}
