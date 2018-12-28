#include <iostream>
#include <algorithm>

int main()
{
  long N, C, K;
  std::cin >> N >> C >> K;
  long T[N];
  for ( int i = 0; i < N; i++ ) std::cin >> T[i];
  std::sort(T, T+N);

  long deadline = T[0] + K;

  long n_buses = 1; 

  for ( long i = 0, cnt = 0; i < N; i++ ) {
    if ( T[i] <= deadline && cnt < C ) cnt++;
    else {
      cnt = 0;
      n_buses++;
      deadline = T[i] + K;
      i--;
    }
  }

  std::cout << n_buses << std::endl;
  return 0;
}
