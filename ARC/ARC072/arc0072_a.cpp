#include <iostream>
#include <algorithm>

int main()
{
  long N;
  std::cin >> N;
  long long a[N];
  for ( long i = 0; i < N; i++ ) std::cin >> a[i];

  long long p = 0, n = 0;
  long long sum = 0;
  
  // when the first element is positive
  if ( a[0] <= 0 ) {
    p += -a[0] + 1;
    sum = 1;
  } else {
    sum += a[0];
  }

  for ( long i = 1; i < N; i++ ) {
    if ( i % 2 == 0 ) {
      if ( sum + a[i] <= 0 ) {
        p += -(sum + a[i]) + 1;
        sum = 1;
      } else sum += a[i];
    } else {
      if ( sum + a[i] >= 0 ) {
        p += (sum + a[i]) + 1;
        sum = -1;
      } else {
        sum += a[i];
      }
    }
    std::cerr << "sum: " << sum << std::endl;
    std::cerr << "p: " << p << std::endl;
  }

  // when the first element is negative
  sum = 0;
  if ( a[0] >= 0 ) {
    n += a[0] + 1;
    sum = -1;
  } else {
    sum += a[0];
  }
  for ( long i = 1; i < N; i++ ) {
    if ( i % 2 == 0 ) {
      if ( sum + a[i] >= 0 ) {
        n += (sum + a[i]) + 1;
        sum = -1;
      } else {
        sum += a[i];
      }
    } else {
      if ( sum + a[i] <= 0 ) {
        n += -(sum + a[i]) + 1;
        sum = 1;
      } else {
        sum += a[i];
      }
    }
    std::cerr << "sum: " << sum << std::endl;
    std::cerr << "n: " << n << std::endl;
  }

  std::cout << std::min(p, n) << std::endl;
  return 0;
}
