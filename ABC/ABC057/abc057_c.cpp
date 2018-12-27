#include <iostream>
#include <cmath>
#include <algorithm>

int cal_n_digits(int n)
{
  int n_digits = 0;
  if ( n == 0 ) return 1;

  while ( n > 0 ) {
    n /= 10;
    n_digits++;
  }

  return n_digits;
}

int main()
{
  long N;
  std::cin >> N;
  long limit = std::sqrt(N);
 
  int min = 3000;
  int f;
  for ( long A = 1; A <= limit; A++ ) {
    if ( N % A != 0 ) continue;
    long B = N / A;
    f = std::max(cal_n_digits(A), cal_n_digits(B));
    if ( f < min ) {
      min = f;
    }
  }
  std::cout << f << std::endl;
  return 0;
}
