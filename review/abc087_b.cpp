#include <iostream>

int main()
{
  int A, B, C, X;
  std::cin >> A >> B >> C >> X;
  int ans = 0;

  for ( int i = 0; i <= A; i++ ) {
    for ( int j = 0; j <= B; j++ ) {
      int total = i * 500 + j * 100;
      int res = X - total;
      if ( res < 0 ) {
        break;
      }
      if ( res % 50 == 0 && res / 50 <= C ) {
        ans++;
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
