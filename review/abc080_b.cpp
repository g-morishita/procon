#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int tmp = N;
  int sum = 0;

  while ( tmp > 0 ) {
    sum += tmp % 10;
    tmp /= 10; 
  }

  if ( N % sum == 0 ) std::cout << "Yes\n";
  else std::cout << "No\n";
  return 0;
}
