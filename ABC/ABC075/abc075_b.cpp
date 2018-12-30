#include <iostream>
#include <string>

int cal(const std::string S[], int i, int j, int W, int H) {
  int n_bombs = 0;
  if ( i-1 >= 0 && j-1 >=0 ) {
    if ( S[i-1][j-1] == '#' ) n_bombs++;
  }

  if ( i-1 >= 0 ) {
    if ( S[i-1][j] == '#' ) n_bombs++;
  }

  if ( i-1 >=0 && j+1 < W ) {
    if ( S[i-1][j+1] == '#' ) n_bombs++;
  }

  if ( j-1 >= 0 ) {
    if ( S[i][j-1] == '#' ) n_bombs++;
  }

  if ( j+1 < W ) {
    if ( S[i][j+1] == '#' ) n_bombs++;
  }

  if ( i+1 < H && j+1 < W ) {
    if ( S[i+1][j+1] == '#' ) n_bombs++;
  }

  if ( i+1 < H ) {
    if ( S[i+1][j] == '#' ) n_bombs++;
  }

  if ( i+1 < H && j-1 >= 0 ) {
    if ( S[i+1][j-1] == '#' ) n_bombs++;
  }
  return n_bombs;
}

int main()
{
  int H, W;
  std::cin >> H >> W;
  
  std::string S[H];
  for ( int i = 0; i < H; i++ ) std::cin >> S[i];
  std::string C[H];
  
  for ( int i = 0; i < H; i++ ) {
    for ( int j = 0; j < W; j++ ) {
      if ( S[i][j] == '.' ) {
        int n_bombs = cal(S, i, j, W, H);
        // std::cerr << n_bombs << std::endl;
        C[i] += std::to_string(n_bombs);
      } else {
        C[i] += '#';
      }
    }
  }
  for ( int i = 0; i < H; i++ ) {
    for ( int j = 0; j < W; j++ ) {
      std::cout << C[i][j];
    }
    std::cout << std::endl;
  }
}
