#include <iostream>
#include <string>
#include <set>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
  std::set<char> chars;
  std::string s;
  std::cin >> s;

  for ( char c : s ) {
    chars.insert(c);
  }

  bool full = true;
  char ans;
  for ( char c : alphabet ) {
    if (!chars.count(c)) {
      full = false;
      ans = c;
      break;
    }
  }
  if ( full ) {
    std::cout << "None\n";
  } else {
    std::cout << ans << std::endl;
  }
  return 0;
}
