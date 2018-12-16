#include <iostream>
#include <cstdlib>

int main()
{
  int N;
  std::cin >> N;
  int t[N + 1];
  int x[N + 1];
  int y[N + 1];

  t[0] = 0;
  x[0] = 0;
  y[0] = 0;

  for ( int i = 1; i <= N; i++ ) {
    std::cin >> t[i] >> x[i] >> y[i];
  }

  bool can_travel = true;
  for ( int i = 0; i < N; i++ ) {
    if ((t[i+1] % 2) != ((x[i+1] + y[i+1]) % 2) || (t[i+1] - t[i]) < std::abs(x[i+1] - x[i]) + std::abs(y[i+1] - y[i])) {
      can_travel = false;
    }
  }
  if ( can_travel ) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
