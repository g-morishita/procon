#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int d[N];
  int b[110] = {0};
  for ( int i = 0; i < N; i++ ) {
    std::cin >> d[i];
    b[d[i]]++;
  }
  int ans = 0;
  for ( int i = 0; i < 101; i++ ) {
    if ( b[i] != 0 ) ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}
