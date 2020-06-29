#include <iostream>
using namespace std;

bool check_can_load(int P, int n, int k, int w[]) {
  int num_trucks = 1;
  for (int i = 0; i < n;) {
    int remain = P;
    while (true) {
      if (remain >= w[i]) {
        remain -= w[i];
        i++;
        if (i >= n) {
          return true;
        }
      } else {
        num_trucks++;
        if (num_trucks > k) return false;
        break;
      }
    }
  }
  return false;
}

int n, k;
const int N = 100000;
int w[N + 5];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int P = 1;
  while(!check_can_load(P, n, k, w)) {
    P++;
  }
  cout << P << endl;
}
