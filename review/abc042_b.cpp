#include <iostream>
#include <algorithm>
#include <string>

int main()
{
  int N, L;
  std::cin >> N >> L;
  std::string S[N];
  for ( int i = 0; i < N; i++ ) std::cin >> S[i];
  std::sort(S, S+N);
  for ( int i = 0; i < N; i++ ) std::cout << S[i];
  std::cout << std::endl;
  return 0;
}
