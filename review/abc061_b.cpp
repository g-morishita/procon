#include <iostream>
#include <map>

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::map<int, int> m;
  for ( int i = 0; i < 2*M; i++ ) {
    int tmp;
    std::cin >> tmp;
    m[tmp]++;
  }
  for ( int i = 1; i <= N; i++ ) {
    std::cout << m[i] << std::endl;
  }
  return 0;
}
