#include <iostream>
#include <algorithm>

int main()
{
  // read the input
  int N;
  int a[100];
  std::cin >> N;
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];

  std::sort(a, a+N, std::greater<int>());
  int Alice = 0;
  int Bob = 0;

  for ( int i = 0; i < N; ++i ) {
    if ( i % 2 == 0 ) {
      Alice += a[i];
    } else {
      Bob += a[i];
    }
  }

  std::cout << Alice - Bob << std::endl;

  return 0;
}
