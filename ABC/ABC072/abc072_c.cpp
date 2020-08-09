#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 100005;

int main() {
  // input
  int N;
  int A[MAX];
  int counting[MAX] {0};
  cin >> N;
  int maxv {0};
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (maxv < A[i]) maxv = A[i];
    counting[A[i]]++;
  }

  int ans {0};
  int tmp_ans {0};

  for (int i = 1; i < MAX-1; i++) {
    tmp_ans = counting[i-1] + counting[i] + counting[i+1];
    if (tmp_ans > ans) ans = tmp_ans;
  }

  cout << ans << endl;
}
