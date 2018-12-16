#include <iostream>

int main()
{
  int N, A;
  std::cin >> N >> A;
  
  if ( (N % 500) <= A ) std::cout << "Yes\n";
  else std::cout << "No\n";

  return 0;
}
