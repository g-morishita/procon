#include <iostream>

int main()
{
  long long int a, b, x;
  std::cin >> a >> b >> x;
  long long int ans = 0;

  ans += b / x + 1;

  if ( a != 0 ) {
    ans-= (a-1) / x + 1;
  }
  
  std::cout << ans << std::endl;
  return 0;
}
