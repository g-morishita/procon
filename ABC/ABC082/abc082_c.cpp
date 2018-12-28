#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int a[N];
  int b[10*10*10*10*10 + 1] = {0};
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];

  for ( int i = 0; i < N; i++ ) {
    b[a[i]]++;
  }

  int max = 0;

  if ( N == 1 ) max = 1;
  if ( N == 2 && (a[0] == a[1] || a[0] == a[1] + 1 || a[0] == a[1] - 1) ) max = 2;
  for ( int i = 0; i < N-1; i++ ) {
    int n_X = b[i] + b[i+1] + b[i+2];
    if ( n_X > max ) max = n_X;
  }

  std::cout << max << std::endl;
  return 0;
}
