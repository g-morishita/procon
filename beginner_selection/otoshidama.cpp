#include <iostream>

int main()
{
  // read the input
  int N, Y;
  std::cin >> N >> Y;

  bool can_pay = false;

  for ( int n_100 = 0; n_100 <= N; n_100++ ) {
    for ( int n_50 = 0; n_50 <= N - n_100; n_50++ ) {
      int n_1 = N - n_100 - n_50;
      int total = n_100 * 10000 + n_50 * 5000 + n_1 * 1000;

      if ( total == Y ) {
        std::cout << n_100  << ' ' << n_50 << ' ' << n_1 << std::endl;
        can_pay = true;
        break;
      }
    }
    if ( can_pay ) break;
  }

  if ( !can_pay ) {
    std::cout << "-1 -1 -1" << std::endl;
  }
  return 0;
}
