#include <iostream>

int cal(long long n) {
  int retv = 0;
  while(true) {
    if ( n % 2 == 0 ) retv++;
    else return retv;

    n /= 2;
  }
  return retv;
}

int main()
{
  int N;
  std::cin >> N;
  long long a[N];
  int ans = 100;
  for ( long long i = 0; i < N; i++ ) {
    std::cin >> a[i];
    int m = cal(a[i]);
    if ( m < ans) {
      ans = m;
    }
  }
  std::cout << ans << std::endl;
}
