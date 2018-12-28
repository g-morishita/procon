#include <iostream>
#include <algorithm>

int main()
{
  int A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;
  int n_a = 0;
  int n_b = 0;
  long min = 2 * 5000 * 10 * 10 * 10 * 10 * 10;

  for ( int n_ab = 0, limit = std::max(2*X, 2*Y); n_ab <= limit; n_ab += 2 ) {
    int total = std::max(A * (X - n_ab/2), 0) + std::max(B * (Y - n_ab/2), 0) + C * n_ab;
    if (total < min) {
      min = total;
    }
  }

  std::cout << min << std::endl;
  return 0;
}
