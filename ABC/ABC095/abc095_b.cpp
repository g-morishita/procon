#include <iostream>

int main()
{
  int N, X;
  std::cin >> N >> X;

  int m[N];
  for ( int i = 0; i < N; i++ ) std::cin >> m[i];

  int sum = m[0];
  int min = m[0];
  for ( int i = 1; i < N; i++ ) {
    sum += m[i];
    if ( min > m[i] ) min = m[i];
  }

  X -= sum;
  std::cout << N + int(X/min) << std::endl;
  
  return 0;
}
