#include <iostream>
#include <algorithm>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int l[N];

  for ( int i = 0; i < N; i++ ) std::cin >> l[i];

  std::sort(l, l + N, std::greater<int>());
  int sum = 0;
  for ( int i = 0; i < K; i++ ) { 
    sum += l[i];
  }

  std::cout << sum << std::endl;
}
