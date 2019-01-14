#include <iostream>
#include <algorithm>

int main()
{
  int N, X;
  std::cin >> N >> X;
  int m[N];
  int sum = 0;
  int ans = 0;
  for ( int i = 0; i < N; i++ ) {
    std::cin >> m[i];
    sum += m[i];
  }
  X -= sum;
  ans += N;

  std::sort(m, m + N);
  int add = X / m[0];
  ans += add;
  std::cout << ans << std::endl;
  return 0;
}
