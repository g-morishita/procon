#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  int N, L;
  std::cin >> N >> L;
  std::string S[N];
  for ( int i = 0; i < N; i++ ) std::cin >> S[i];

  std::sort(S, S+N);
  std::string ans = "";
  for ( std::string s : S ) {
    ans += s;
  }

  std::cout << ans << std::endl;
  return 0;
}
