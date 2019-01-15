#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;
  int a[N];
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];

  std::sort(a, a+N, std::greater<int>());
  int alice = 0;
  int bob = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( i % 2 == 0 ) alice += a[i];
    else bob += a[i];
  }
  std::cout << alice - bob << std::endl;
  return 0;
}
