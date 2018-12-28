#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int n_odd = 0;

  for ( int i = 0; i < N; i++ ) {
    long tmp;
    std::cin >> tmp;
    if ( tmp % 2 == 1 ) n_odd++;
  }

  if ( n_odd % 2 == 0 ) std::cout << "YES\n";
  else std::cout << "NO\n";
}
