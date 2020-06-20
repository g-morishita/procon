#include <iostream>
using namespace std;

int main() {
  long a {0}, b {0};
  cin >> a >> b;
  if (b > a) {
    long tmp = a;
    a = b;
    b = tmp;
  }
  while (b > 1) {
    long tmp = b;
    b = a % b;
    a = tmp;
  }
  if (b == 1) {
    cout << 1 << endl;
  } else {
    cout << a << endl;
  }
}
