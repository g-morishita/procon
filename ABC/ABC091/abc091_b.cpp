#include <iostream>
#include <string>
#include <map>

int main()
{
  int N;
  std::cin >> N;
  std::map<std::string, int> point;
  for ( int i = 0; i < N; i++ ) {
    std::string s;
    std::cin >> s;
    point[s]++;
  }

  int M;
  std::cin >> M;
  for ( int i = 0; i < M; i++ ) {
    std::string s;
    std::cin >> s;
    point[s]--;
  }
  int max = 0;
  for ( auto it = point.begin(); it != point.end(); it++ ) {
    int count = it->second;
    if ( max < count ) {
      max = count;
    }
  }
  if (max < 0) max = 0;
  std::cout << max << std::endl;
  return 0;
}
