#include <iostream>
#include <string>

int bucket[26];

int main()
{
  std::string S;
  std::cin >> S;

  for ( char c : S ) {
    int index = int(c) - 97;
    bucket[index]++;
  }

  bool is_missing = false;
  for ( int i = 0; i < 26; i++ ) {
    if ( bucket[i] == 0 ) { 
      std::cout << char( i + 97 ) << std::endl;
      is_missing = true;
      break;
    }
  }
  if ( !is_missing ) std::cout << "None\n";
  return 0;
}
