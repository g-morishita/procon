#include <iostream>
#include <algorithm>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int b[N] = {0};
  for ( int i = 0; i < N; i++ ) {
    int a;
    std::cin >> a;
    b[a-1]++;
  }

  int count = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( b[i] != 0 ) {
      count++;
    }
  }

  std::sort(b, b+N);
  int ans = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( K >= count ) break;
    if ( b[i] != 0 ) {
      count--;
    }
    ans += b[i];
  }

  std::cout << ans << std::endl;
  return 0;
}
