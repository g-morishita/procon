#include <iostream>
#include <cmath>
#include <map>

int main()
{
  int N;
  std::cin >> N;
  std::map<int, int> mp;

  for ( int i = 0; i < N; i++ ) {
    int a;
    std::cin >> a;
    mp[a]++;
  }
  
  int ans = 0;
  for ( auto itr = mp.begin(); itr != mp.end(); ++itr ) {
    if ( itr->second % 2 == 1 ) {
      ans++;
    }
  }

  std::cout << ans << std::endl;
}
