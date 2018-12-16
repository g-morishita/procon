#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;
  S[3] = '8';

  std::cout << S << std::endl;

  return 0;
}
