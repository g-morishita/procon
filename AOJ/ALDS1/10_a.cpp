#include <iostream>
using namespace std;

const int MAX = 100;
long long dp[MAX];

long long fb(int n) {
  if (n < 2) {
    return 1;
  }
  if (dp[n] != 0) {
    return dp[n];
  } else {
    return dp[n] = fb(n-1) + fb(n-2);
  }
}

int main() {
  int n;
  cin >> n;
  cout << fb(n) << endl;
  return 0;
}
