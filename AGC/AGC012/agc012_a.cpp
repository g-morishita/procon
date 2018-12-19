#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;
  long a[3 * N];
  for ( int i = 0; i < 3 * N; i ++ ) std::cin >> a[i];
  
  std::sort(a, a+3*N, std::greater<int>());
  long sum = 0;
  for ( int i = 0; i < N; i++ ) {
    sum += a[2*i+1];
  }

  std::cout << sum << std::endl;
  return 0;
}
