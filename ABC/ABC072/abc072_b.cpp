#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;

  for ( int i = 0, len = s.size(); i < len; i += 2 ) std::cout << s[i];
  std::cout << std::endl;

  return 0;
}
