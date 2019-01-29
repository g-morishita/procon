#include <iostream>
#include <string>
#include <map>

int main()
{
  int N;
  std::cin >> N;
  std::string s[N];
  for ( int i = 0; i < N; i++ ) std::cin >> s[i];
  int M;
  std::cin >> M;
  std::string t[M];
  for ( int i = 0; i < M; i++ ) std::cin >> t[i];

  std::map<std::string, int> m;
  for ( int i = 0; i < N; i++ ) {
    m[s[i]]++;
  }
  for ( int i = 0; i < M; i++ ) {
    m[t[i]]--;
  }
  int max = 0;
  for ( auto i = m.cbegin(); i != m.cend(); i++ ) {
    if ( i -> second > max ) {
      max = i -> second;
    }
  }
  std::cout << max << std::endl;
  return 0;
}
