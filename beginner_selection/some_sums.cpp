#include <iostream>

int main()
{
  // read the input
  int N;
  int A, B;
  std::cin >> N >> A >> B;

  int ans = 0;

  for ( int i = 1; i <= N; i++ ) {
    int num = i;
    int sum = 0;
    while ( num != 0 ) {
      sum += (num % 10);
      num /= 10;
    }
    if ( A <= sum && sum <= B ) ans += i;
  }

  std::cout << ans << std::endl;
  
  return 0;
}
