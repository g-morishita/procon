#include <iostream>
using namespace std;

long long check_can_load(long long P, int n, int k, int w[]) {
  int num_trucks = 1;
  for (int i = 0; i < n;) {
    long long remain = P;
    while (true) {
      if (remain >= w[i]) {
        remain -= w[i];
        i++;
        if (i >= n) {
          return n;
        }
      } else {
        num_trucks++;
        if (num_trucks > k) return i;
        break;
      }
    }
  }
  return 0;
}

int n, k;
const long long N = 100000;
int w[N + 5];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  long long left = 0;
  long long right = N * N;
  long long mid = (right + left) / 2;
  long long packages {0};
  while (right - left > 1) {
    packages = check_can_load(mid, n, k, w);
    if (packages < n) {
      left = mid;
    } else if (packages >= n) {
      right = mid;
    }
    mid = (right + left) / 2;
  }
  cout << right << endl;
  return 0;
}
