#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int key) {
  int left = 0;
  int right = n;
  int mid {0};
  while (left < right) {
    mid = (left + right) / 2;
    if (key < A[mid]) {
      right = mid;
    } else if (key > A[mid]) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

const int MAX {100000};
int S[MAX];
int T[MAX];
int n, q;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> T[i];

  int ans {0};
  for (int i = 0; i < q; i++) {
    if (binarySearch(S, n, T[i]) != -1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
