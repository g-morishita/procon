#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  int len = s.size();
  for ( int i = 0; i < len; i += 2 ) {
    std::cout << s[i];
  }
  std::cout << std::endl;
  return 0;
}
