#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int ans = 0;
  for ( int i = 1; i <= N; i++ ) {
    if ( N < std::pow(2, i) ) {
      ans = std::pow(2, i-1);
      break;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
