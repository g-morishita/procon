#include <iostream>
#include <string>

int main()
{
  std::string input;
  std::cin >> input;
  int a[4];
  for ( int i = 0; i < 4; i++ ) a[i] = input[i] - '0';

  for ( int x = 0; x < 8; x++ ) {
    int sum = a[0];
    std::string S;
    S += (char)('0' + a[0]);
    for ( int i = 0; i < 3; i++ ) {
      if ( x & (1<<i) ) {
        sum += a[i+1];
        S += '+';
        S += (char)('0' + a[i+1]);
      } else {
        sum -= a[i+1];
        S += '-';
        S += (char)('0' + a[i+1]);
      }
    }
    if ( sum == 7 ) {
      std::cout << S << "=7" << std::endl;
      return 0;
    }
  }
  return 0;
}
