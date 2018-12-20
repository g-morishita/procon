#include <iostream>

int main()
{
  int W, H, N;
  std::cin >> W >> H >> N;
  int origin_x = 0;
  int origin_y = 0;
  int x[N];
  int y[N];
  int a[N];

  for ( int i = 0; i < N; i++ ) std::cin >> x[i] >> y[i] >> a[i];
  
  for ( int i = 0; i < N; i++ ) {
    if ( a[i] == 1 ) {
      if ( origin_x < x[i] ) {
        origin_x = x[i];
      }
    } else if ( a[i] == 2 ) {
      if ( W > x[i] ) {
        W = x[i];
      }
    } else if ( a[i] == 3 ) {
      if ( origin_y < y[i] ) {
        origin_y = y[i];
      }
    } else if ( a[i] == 4 ) {
      if ( H > y[i] ) {
        H = y[i];
      }
    }
  }

  long area = (W - origin_x) * (H - origin_y);
  if ( area > 0 ) std::cout << area << std::endl;
  else std::cout << 0 << std::endl;
  return 0;
}
