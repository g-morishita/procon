#include <iostream>
#include <algorithm>

int main()
{
  int N, x;
  std::cin >> N >> x;
  int a[N];
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];
  std::sort(a, a+N);
  int ans = 0;
  bool all = true;
  for ( int i = 0; i < N; i++ ) {
    if ( x >= a[i] ) {
      ans++;
      x -= a[i];
    } else {
      all = false;
      break;
    }
  }
  if ( all & x > 0 ) ans--;
  std::cout << ans << std::endl;
  return 0;
}
