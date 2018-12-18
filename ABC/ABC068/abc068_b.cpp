#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;

  int ans = 0;
  while ( ans <= N ) {
    if ( N < std::pow(2, ans) ) {
      ans--;
      break;
    }
    ans++; 
  }

  std::cout << std::pow(2, ans) << std::endl;
  return 0;
}
