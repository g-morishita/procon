#include <iostream>
using namespace std;

const long long MAX = 100005;

int main() {
  long long n;
  long long tmp;
  long long ans1 {0};
  long long ans2 {0};
  cin >> n;
  long long A[MAX], B[MAX];
  long long cum_sum = 0;

  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    cum_sum += tmp;
    A[i] = cum_sum;
    B[i] = cum_sum;
  }

  // When making A[0] > 0
  tmp = 0;
  if (A[0] <= 0) {
    tmp = -A[0] + 1;
    ans1 += tmp;
    for (long long i = 0; i < n; i++) {
      A[i] += tmp;
    }
  }
  for (long long i = 0; i < n-1; i++) {
    if (A[i] > 0) {
      if (A[i+1] >= 0) {
        tmp = (A[i+1] + 1);
        ans1 += tmp;
        for (long long j = i+1; j < n; j++) A[j] -= tmp;
      }
    } else if (A[i] < 0) {
      if (A[i+1] <= 0) {
        tmp = (-A[i+1] + 1);
        ans1 += tmp;
        for (long long j = i+1; j < n; j++) A[j] += tmp;
      }
    } 
  }

  // when making B[0] < 0
  tmp = 0;
  if (B[0] >= 0) {
    tmp = B[0] + 1;
    ans2 += tmp;
    for (long long i = 0; i < n; i++) {
      B[i] -= tmp;
    }
  }
  for (long long i = 0; i < n-1; i++) {
    if (B[i] > 0) {
      if (B[i+1] >= 0) {
        tmp = (B[i+1] + 1);
        ans2 += tmp;
        for (long long j = i+1; j < n; j++) B[j] -= tmp;
      }
    } else if (B[i] < 0) {
      if (B[i+1] <= 0) {
        tmp = (-B[i+1] + 1);
        ans2 += tmp;
        for (long long j = i+1; j < n; j++) B[j] += tmp;
      }
    } 
  }
  long long ans = (ans1 > ans2 ? ans2 : ans1);
  cout << ans << endl;
}
