#include <iostream>

int main()
{
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  long price = 0;
  if ( 2 * c < a + b ) {
    if ( x > y ) {
      price += 2 * c * y;
      x -= y;
      if ( 2 * c < a ) {
        price += 2 * c * x;
      } else {
        price += a * x;
      }
    } else {
      price += 2 * c * x;
      y -= x;
      if ( 2 * c < b ) {
        price += 2 * c * y;
      } else {
        price += b * y;
      }
    }
  } else {
    price = a * x + b * y;
  }
  std::cout << price << std::endl;
  return 0;
}
