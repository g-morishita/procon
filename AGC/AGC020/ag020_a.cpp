#include <iostream>

int main()
{
  int N, A, B;
  std::cin >> N >> A >> B;
  
  if ( N == 2 || (B - A - 1) % 2 == 0 ) std::cout << "Borys\n";
  else std::cout << "Alice\n"; 

  return 0;
}
