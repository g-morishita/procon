#include <iostream>
#include <cmath>
using namespace std;

bool check_prime(long n) {
  long limit = long(sqrt(n));
  for (long i = 2; i <= limit; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N {0};
  long total {0};
  cin >> N;
  for (int i = 0; i < N; i++) {
    long tmp;
    cin >> tmp;
    if (check_prime(tmp)) {
      total++;
    }
  }

  cout << total << endl;
}
