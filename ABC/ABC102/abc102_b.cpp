#include <iostream>
#include <cmath>

int main()
{
  int N;
  std::cin >> N;
  int A[N];
  for ( int i = 0; i < N; i++ ) std::cin >> A[i];

  int ans = 0;

  for ( int i = 0; i < N; i++ ) {
    for ( int j = i+1; j < N; j++ ) {
      int diff = std::abs(A[i] - A[j]); 
      if ( ans < diff ) {
        ans = diff;
      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
