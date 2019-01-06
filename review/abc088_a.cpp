#include <iostream>

int main()
{
  int N, A;
  std::cin >> N >> A;

  int rest = N % 500;
  std::cerr << rest << std::endl;
  if ( rest <= A ) std::cout << "Yes\n";
  else std::cout << "No\n";

  return 0;
}
