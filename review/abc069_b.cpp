#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  std::string ans = s[0] + std::to_string(s.size() - 2) + s[s.size() - 1];
  std::cout << ans << std::endl;
  return 0;
}
