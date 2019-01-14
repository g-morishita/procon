#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::string s, t;
  std::cin >> s >> t;
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end(), std::greater<int>());
  if ( s < t ) std::cout << "Yes\n";
  else std::cout << "No\n";
  return 0;
}
