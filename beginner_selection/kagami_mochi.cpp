#include <iostream>
#include <algorithm>

int main()
{
  int N;
  int a[101];
  std::cin >> N;
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];

  int num[100] = {0};
  for ( int i = 0; i < N; i++ ) {
    num[a[i]]++;
  }

  int ans = 0;
  for ( int i = 1; i <= 100; i++ ) {
    if ( num[i] > 0 ) {
      ans++;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
