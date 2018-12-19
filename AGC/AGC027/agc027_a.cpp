#include <iostream>
#include <algorithm>

int main()
{
  int N, x;
  std::cin >> N >> x;
  int a[N];
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];
  
  std::sort(a, a + N);
  int ans = 0;

  bool is_all = false;
  for ( int i = 0; i < N; i++ ) {
    if ( x >= a[i] ) {
      x -= a[i];
      ans++;
      if ( i == N - 1 ) is_all = true;
    } else {
      break;
    }
  }
  if ( x > 0 && is_all ) ans--;

  std::cout << ans << std::endl;
  return 0;
}
