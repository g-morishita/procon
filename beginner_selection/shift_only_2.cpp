#include <iostream>

int count_power_2(int num) {
  int n_pow2 = 0; // how many times the number can be divied by 2

  while ( true ) {
    bool is_odd = false;
    if ( num % 2 == 0 ) {
      num /= 2;
      n_pow2++;
    } else {
      is_odd = true;
    }

    if ( is_odd ) break;
  }

  return n_pow2;
}

int A[200];

int main()
{
  // read the input
  int N;
  std::cin >> N;
  for ( int i = 0; i < N; i++ ) std::cin >> A[i];

  int min_pow2 = count_power_2(A[0]);

  for ( int i = 1; i < N; i++ ) {
    int n_pow2 = count_power_2(A[i]);
    if ( n_pow2 < min_pow2 ) {
      min_pow2 = n_pow2;
    }
  }

  std::cout << min_pow2 << std::endl;

  return 0;
}
