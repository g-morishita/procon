#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  int sum = 0;
  int tmp = N;
  while ( N > 0 ) {
    sum += N % 10;
    N /= 10;
  }

  if ( tmp % sum == 0 ) std::cout << "Yes\n";
  else std::cout << "No\n";

  return 0;
}
