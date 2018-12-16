#include <iostream>

int main()
{
  // read the input
  int A, B, C, X;
  std::cin >> A >> B >> C >> X;

  int n_ways_pay = 0;
  
  for ( int n_500 = 0; n_500 <= A; n_500++ ) {
    for ( int n_100 = 0; n_100 <= B; n_100++ ) {
      int rest = X - 500 * n_500 - 100 * n_100;
      if (rest >= 0 && rest % 50 == 0 && (rest / 50) <= C) {
        n_ways_pay++;
      }
    }
  }

  std::cout << n_ways_pay << std::endl;

  return 0;
}
