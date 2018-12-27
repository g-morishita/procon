#include <iostream>
#include <algorithm>

int main()
{
  long N;
  std::cin >> N;
  long long A[N];

  for ( long i = 0; i < N; i++ ) std::cin >> A[i];

  long how_many = 1;
  long index = 1;

  while ( true ) {
    long temp_i = index;
    while (temp_i < N && A[temp_i] - A[temp_i-1] >= 0) {
      temp_i++;
    }
    
    long temp_j = index;
    while (temp_j < N && A[temp_j] - A[temp_j-1] <= 0) {
      temp_j++;
    }
    index = std::max(temp_i, temp_j) + 1;
    if ( index > N ) break;
    how_many++;
  }

  std::cout << how_many << "\n";
  return 0;
}
