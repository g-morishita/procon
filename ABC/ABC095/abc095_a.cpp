#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;

  int cnt = 0;

  for ( char c : S ) {
    if ( c == 'o' ) cnt++;
  }

  std::cout << 700 + 100 * cnt << std::endl;

  return 0;
}
