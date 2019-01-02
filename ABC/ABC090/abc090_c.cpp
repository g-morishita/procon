#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int A[2*N];
  int ans = 0;
  for ( int i = 0; i < 2*N; i++ ) std::cin >> A[i];
  ans += A[0];
  ans += A[2*N - 1];
  A[0] = 0;
  A[2*N - 1] = 0;

  int up[N] = {0};
  int down[N] = {0};

  for ( int i = 0; i < N; i++ ) {
    for ( int j = N-1; j >= i; j--) {
      up[i] += A[(j+1) % N];
      down[i] += A[N + j];
    }
  }
  int index;

  // for ( int i = 0; i < N; i++ ) {
  //   std::cerr << "up[" << i << "]: " << up[i] << std::endl;
  //   std::cerr << "down[" << i << "]: " << down[i] << std::endl;
  // }
  for ( int i = 0; i < N; i++ ) {
    if ( up[i] <= down[i] ) {
      index = i;
      break;
    }
  }

  for ( int i = 0; i < N; i++ ) {
    if ( i == index ) {
      ans += A[i];
      ans += A[i+N];
    } else if ( i > index ) {
      ans += A[i+N];
    } else {
      ans += A[i];
    }
  }
  // std::cerr << "index: " << index << std::endl;
  std::cout << ans << std::endl;
  return 0;
}
