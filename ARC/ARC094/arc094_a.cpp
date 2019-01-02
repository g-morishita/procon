#include <iostream>
#include <algorithm>

int main()
{
  int a[3];
  for ( int i = 0; i < 3; i++ ) std::cin >> a[i];
  std::sort(a, a+3);

  if ( (a[2]-a[0]) % 2 == 0 && (a[2]-a[1]) % 2 == 0 ) {
    std::cout << (a[2] - a[0]) / 2 + (a[2] - a[1]) / 2 << std::endl;
  } else if ( (a[2] - a[0]) % 2 == 1 && (a[2] - a[1]) % 2 == 0 ) { 
    std::cout << 1 + (a[2] + 1 - a[0]) / 2 + (a[2] - a[1]) / 2 << std::endl;
  } else if ( (a[2] - a[0]) % 2 == 0 && (a[2] - a[1]) % 2 == 1 ) {
    std::cout << 1 + (a[2] - a[0]) / 2 + (a[2] + 1 - a[1]) / 2 << std::endl;
  } else {
    std::cout << 1 + (a[2] - a[0] - 1) / 2 + (a[2] - a[1] - 1) / 2 << std::endl;
  }
  return 0;
}
