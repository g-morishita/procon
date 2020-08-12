#include <iostream>
using namespace std;

int main() {
  int n;
  long long tmp, sum {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
  }
  cout << tmp << endl;
}
