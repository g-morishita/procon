#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  
  int begin, end;
  int len = s.size();
  for ( int i = 0; i < len; i++ ) {
    if ( s[i] == 'A' ) {
      begin = i;
      break;
    }
  }
  for ( int i = len; i > 0; i-- ) {
    if ( s[i] == 'Z' ) {
      end = i;
      break;
    }
  }

  std::cout << end - begin + 1 << std::endl;
  return 0;
}
