#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;
  long long int a[3*N];
  long long int ans = 0;
  for ( int i = 0; i < 3*N; i++ ) std::cin >> a[i];
  std::sort(a, a+3*N, std::greater<int>());
  for ( int i = 1; i <= 2*N; i += 2 ) ans += a[i];
  std::cout << ans << std::endl;
  return 0;
}
