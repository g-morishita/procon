#include <iostream>
#include <cmath>

int main()
{
  int N, K;
  std::cin >> N >> K;

  long long ans = std::pow(K-1, N-1) * K;
  std::cout << ans << std::endl;
  return 0;
}
