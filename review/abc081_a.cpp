#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  int ans = 0;
  for ( int i = 0; i < 3; i++ ) {
    if ( s[i] == '1' ) ans++;
  }

  std::cout << ans << std::endl;
  return 0;
}
