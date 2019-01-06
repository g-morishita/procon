#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  int A[n];
  int B[n];
  for ( int i = 0; i < n; i++ ) std::cin >> A[i];
  for ( int i = 0; i < n; i++ ) std::cin >> B[i];

  int max = 0;

  for ( int i = 0; i < n; i++ ) {
    int tmp = 0;
    for ( int j = i; j < n; j++ ) {
      tmp += B[j];
    }
    for ( int k = 0; k <= i; k++ ) {
      tmp += A[k];
    }
    if ( tmp > max ) {
      max = tmp;
    }
  }

  std::cout << max << std::endl;
  return 0;
}
