#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  int A, B;
  std::cin >> A >> B;

  int ans = 0;
  for ( int i = A; i <= B; i++ ) {
    std::string s = std::to_string(i);
    std::string org = s;
    std::reverse(s.begin(), s.end());
    std::cerr << s << ' ' << org << std::endl;
    if ( s == org ) ans++;
  }

  std::cout << ans << std::endl;
  return 0;
}
