#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  long long a[N];
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];
  long long max = a[0];
  long long min = a[0];
  for ( int i = 1; i < N; i++ ) {
    if ( a[i] > max ) max = a[i];
    if ( a[i] < min ) min = a[i];
  }

  std::cout << max - min << std::endl;
  return 0;
}
