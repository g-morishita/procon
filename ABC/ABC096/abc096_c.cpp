#include <iostream>
#include <string>

bool check(std::string s[], int i, int j, int H, int W) 
{
  bool can = false;
  if ( i - 1 >= 0 ) {
    can =  s[i-1][j] == '#';
  }
  if ( !can && i + 1 < H ) {
    can =  s[i+1][j] == '#';
  }
  if ( !can && j - 1 >= 0 ) {
    can =  s[i][j-1] == '#';
  }
  if ( !can &&  j + 1 < W ) {
    can =  s[i][j+1] == '#';
  }
  return can;
}

int main()
{
  int H, W;
  std::cin >> H >> W;
  
  std::string s[H];
  for ( int i = 0; i < H; i++ ) std::cin >> s[i];

  bool can_draw = true;
  for ( int i = 0; i < H; i++ ) {
    for ( int j = 0; j < W; j++ ) {
      if ( s[i][j] == '#' && !check(s, i, j, H, W) ) {
        can_draw = false;
        break;
      }
    }
  }
  if ( can_draw ) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}
