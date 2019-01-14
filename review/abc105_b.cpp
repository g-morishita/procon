#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int limit_4 = N / 4 + 1;
  int limit_7 = N / 7 + 1;
  bool can = false;
  for (int i = 0; i <= limit_4; i++) {
    for ( int j = 0; j <= limit_7; j++ ) {
      int total = 4 * i + 7 * j;
      if ( total == N ) can = true;
    }
  }
  if (can) std::cout << "Yes\n";
  else std::cout << "No\n";
  return 0;
}
