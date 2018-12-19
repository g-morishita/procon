#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  int min = 999999999;
  for ( int i = 1; i <= N /2; i++ ) {
    int A = i;
    int B = N - i;
    int sum = 0;
    while ( A > 0 || B > 0 ) {
      sum += ( A % 10 ) + ( B % 10 );
      A /= 10;
      B /= 10;
    }
    if ( sum < min ) {
      min = sum;
    }
  }
  std::cout << min << std::endl;
  return 0;
}
