#include <iostream>

int main()
{
  int N, M;
  std::cin >> N >> M;
  int roads[2*M];
  for ( int i = 0; i < 2 * M; i ++ ) std::cin >> roads[i];

  int b[N] = {0};
  for ( int i = 0; i < 2 * M; i++ ) {
    b[roads[i] - 1]++;
  }

  for ( int i = 0; i < N; i++ ) {
    std::cout << b[i] << std::endl;
  }
}
