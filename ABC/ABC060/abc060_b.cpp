#include <iostream>

int main()
{
  int A, B, C;
  std::cin >> A >> B >> C;

  bool can = false;

  for ( int i = 1; i <= B; i++ ) {
    int r = i * A % B;
    if ( r == C ) {
      can = true;
      break;
    }
  }
  std::cout << (can ? "YES" : "NO") << std::endl;
  return 0;
}
