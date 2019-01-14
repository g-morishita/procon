#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  int p = 700;
  for ( int i = 0; i < 3; i++ ) {
    if ( s[i] == 'o' ) p += 100;
  }
  std::cout << p << std::endl;
  return 0;
}
