#include <iostream>

int main()
{
  int A, B, C, D, E, F;
  std::cin >> A >> B >> C >> D >> E >> F;

  int unit_F = F / 100;
  int limit_a = unit_F / A;
  int limit_b = unit_F / B;
  double max_ratio = 0;
  int max_sugar = 0;
  int max_sugar_water = 0;
  
  for ( int i = 0; i <= limit_a; i++ ) {
    for ( int j = 0; j <= limit_b; j++ ) {
      if ( i == 0 && j == 0 ) continue;

      int total_water = i * A * 100 + j * B * 100;
      if ( total_water > F ) continue;

      int limit_sugar = E * (i * A + j * B);

      int limit_c = limit_sugar / C;
      int limit_d = limit_sugar / D;

      for ( int k = 0; k <= limit_c; k++ ) {
        for ( int l = 0; l <= limit_d; l++ ) {
          int total_sugar = k * C + l * D;
          int total_sugar_water = total_water + total_sugar;
          if ( total_sugar > limit_sugar ||  total_sugar_water > F ) continue;

          double ratio = double(total_sugar) / double(total_sugar_water);
          if ( ratio > max_ratio ) {
            max_ratio = ratio; 
            max_sugar = total_sugar;
            max_sugar_water = total_sugar_water;
          }
        }
      }
    }
  }

  std::cout << max_sugar_water << ' ' << max_sugar << std::endl;
  return 0;
}
