#include <iostream>
using namespace std;

int main() {
  // input
  int n {0};
  cin >> n;
  int tmp {0};
  cin >> tmp;
  int minv = tmp;
  int ans = -(1 << 30);

  for (int i = 1; i < n; i++) {
    cin >> tmp;
    if (ans <= tmp - minv) {
      ans = tmp - minv;
    }
    if (minv >= tmp) minv = tmp;
  }

  cout << ans << endl;
  return 0;
}
