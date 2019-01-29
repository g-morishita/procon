#include <iostream>

int main()
{
  int n;
  long long int y;
  std::cin >> n >> y;
  for ( int i = 0; i <= n; i++ ) {
    for ( int j = 0; j <= n - i; j++ ) {
      long long total = i * 10000 + j * 5000 + (n-i-j) * 1000;
      if ( total == y ) {
        std::cout << i << ' ' << j << ' ' << n - i -j << std::endl;
        return 0;
      }
    }
  }
  std::cout << "-1 -1 -1\n";
  return 0;
}
