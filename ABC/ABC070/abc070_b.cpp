#include <iostream>
#include <algorithm>

int main()
{
  int A, B, C, D;
  std::cin >> A >> B >> C >> D;
  int ans;

  if ( A <= C ) {
    if ( B <= D ) {
      ans = std::max(B-C, 0);
    } else {
      ans = D - C;
    }
  } else {
    if ( D <= B ) {
      ans = std::max(D-A, 0);
    } else {
      ans = B - A;
    }
  }

  std::cout << ans << std::endl;
}
