#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;
  if ( (a*b) % 2 == 0 ) std::cout << "Even\n";
  else std::cout << "Odd\n";
  return 0;
}
