#include <iostream>
#include <string>

int main()
{
  int N;
  std::cin >> N;
  std::string S;  
  std::cin >> S;
  int sum_w[N] = {0};
  int sum_e[N] = {0};
  if ( S[0] == 'W' ) sum_w[1] = 1;
  if ( S[N-1] =='E' ) sum_e[N-2] = 1;

  for ( int i = N-3; i >= 0; i-- ) {
    if ( S[i+1] == 'E' ) {
      sum_e[i] = sum_e[i+1] + 1; 
    } else {
      sum_e[i] = sum_e[i+1];
    }
  }
  for ( int i = 2; i < N; i++ ) {
    if ( S[i-1] == 'W' ) {
      sum_w[i] = sum_w[i-1] + 1; 
    } else {
      sum_w[i] = sum_w[i-1];
    }
  }
  // for ( int i = 0; i < N; i++ ) {
  //   std::cerr << "sum_w[" << i << "]: " << sum_w[i];
  // }
  // std::cerr << std::endl;
  // for ( int i = 0; i < N; i++ ) {
  //   std::cerr << "sum_e[" << i << "]: " << sum_e[i];
  // }
  // std::cerr << std::endl;

  int min = 10 * 10 * 10 * 10 * 10 * 10;
  for ( int i = 0; i < N; i++ ){
    int tmp = sum_w[i] + sum_e[i];
    // std::cerr << "tmp: " << tmp << std::endl;
    if ( min > tmp ) {
      // std::cerr << "min: " << min << std::endl;
      min = tmp;
    }
  }
  std::cout << min << std::endl;
  return 0;
}
