#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());

  std::string T[] = {"maerd", "remaerd", "esare", "resare"};

  bool can_make = true;
  for ( int i = 0; i < s.size(); ) {
    bool can_include = false;
    for ( int j = 0; j < 4; j++ ) {
      std::string d = T[j];
      if ( s.substr(i, d.size()) == d ) {
        can_include = true;
        i += d.size();
      }
    }
    if( !can_include ) {
      can_make = false;
      break;
    }
  }

  if ( can_make ) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
