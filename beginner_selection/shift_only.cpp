#include <iostream>

int A[200];

int main()
{
  // read the input
  int N;
  int ans = 0;
  std::cin >> N;
  for ( int i = 0; i < N; i++ ) { std::cin >> A[i]; }

  // repeat the operation as many times as possible
  while ( true ) {
    bool exist_odd = false;

    // check if all the elements are even
    for ( int i = 0; i < N; i++ ) {
      if ( A[i] % 2 == 1 ) {
        exist_odd = true; // if some element is odd, raise a flag
        break;
      }
    }

    // if so, count up and divide all of them by 2
    // if not, break the while loop
    if ( !exist_odd ) {
      for ( int i = 0; i < N; i++ ){
        A[i] /= 2;
      }
      ans++;
    } else {
      break;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
