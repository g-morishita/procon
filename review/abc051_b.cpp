#include <iostream>

int main()
{
  int K, S;
  std::cin >> K >> S;
  int count = 0;
  for ( int x = 0; x <= K; x++ ) {
    for ( int y = 0; y<= K; y++ ) {
      if (x + y <= S && (S-x-y) <= K) {
        count++;
      }
    }
  }
  std::cout << count << std::endl;
  return 0;
}
