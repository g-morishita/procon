#include <iostream>

int cal(int n)
{
  int retval = 0;

  while( n > 0 ) {
    retval += n % 10;
    n /= 10;
  }
  return retval;
}

int main()
{
  int N;
  int min = 999999;
  std::cin >> N;
  for ( int a = 1; a < N; a++ ) {
    int b = N - a;
    int tmp = cal(a) + cal(b);
    if ( min > tmp ) min = tmp;
  }
  std::cout << min << std::endl;
  return 0;
}
