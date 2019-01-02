#include <iostream>
#include <cmath>

int main()
{
  int N;
  long long d = std::pow(10, 9) + 7;
  std::cin >> N;
  long long ans = 1;
  for ( int i = 1; i <= N; i++ ) {
    ans *= i;
    ans %= d;
  }
  
  std::cout << ans << std::endl;
  return 0;
}
