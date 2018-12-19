#include <iostream>

int main()
{
  int K, S;
  std::cin >> K >> S;
  
  int ans = 0;

  for ( int x = 0; x <= K; x++ ) {
    for ( int y = 0; y <= K; y++ ) {
      int max_z = S - (x+y);
      if (max_z >= 0 && max_z <= K) {
        ans++;
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
