#include <iostream>

int main()
{
  int N, A, B;
  std::cin >> N >> A >> B;
  int ans = 0;

  for ( int i = 1; i <= N; i++ ) {
    int tmp = i;
    int sum = 0;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if ( A <= sum && sum <= B ) ans += i;
  }
  std::cout << ans << std::endl;
  return 0;
}
