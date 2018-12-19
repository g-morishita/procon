#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  int limit_7 = N / 7;
  int limit_4 = N / 4;

  bool can = false;
  for ( int i = 0; i <= limit_7; i++ ) {
    for ( int j =0; j <= limit_4; j++ ) {
      if ( N == i * 7 + j * 4 ) {
        can = true;
        break;
      }
    }
  }

  if ( can ) std::cout << "Yes\n";
  else std::cout << "No\n";
}
