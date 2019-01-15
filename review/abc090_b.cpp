#include <iostream>
#include <string>

int main()
{
  int A, B;
  std::cin >> A >> B;
  int ans = 0;
  for ( int n = A; n <= B; n++ ) {
    std::string s = std::to_string(n);
    int len = s.size();
    bool can = true;

    for ( int i = 0; i < len/2; i++ ) {
      if ( s[i] != s[len-i-1] ) {
        can = false;
        break;
      }
    }
    if (can) ans++;
  }
  std::cout << ans << std::endl;
}
