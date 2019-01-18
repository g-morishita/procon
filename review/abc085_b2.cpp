#include <iostream>
#include <set>

int main()
{
  int N;
  std::cin >> N;
  int d[N];
  std::set<int> values;
  for ( int i = 0; i < N; i++ ) {
    std::cin >> d[i];
    values.insert(d[i]);
  }
  std::cout << values.size() << std::endl;
  return 0;
}
