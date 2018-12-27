#include <iostream>

int main()
{
  int c[3][3];
  for ( int i = 0; i < 3; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      std::cin >> c[i][j];
    }
  }

  bool can = true;
  for ( int i = 0; i < 2; i++ ) {
    for ( int j = 0; j < 2; j++ ) {
      if (c[j+1][i+1] - c[j][i+1] != c[j+1][i] - c[j][i]) {
        can = false;
      }
    }
  }
  for ( int i = 0; i < 2; i++ ) {
    for ( int j = 0; j < 2; j++ ) {
      if (c[j+1][i+1] - c[j+1][i] != c[j+1][i+1] - c[j+1][i]) {
        can = false;
      }
    }
  }

  if ( can ) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
