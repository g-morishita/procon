#include <iostream>
using namespace std;

const int MAX = 100005;

int binarySearch(int A[], int n, int key) {
  int left = 0;
  int right = n;
  int mid {0};
  int index = -1;
  while (left < right) {
    mid = (left + right) / 2;
    if (A[mid] == key) {
      return mid;
    } else if (A[mid] > key) {
      right = mid;
    } else if (A[mid] < key) {
      left = mid + 1;
    }
  }
  return index;
}

int main() {
  // input
  int n {0}, q{0}, cnt {0};
  int S[MAX];
  int T[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];

  cin >> q;
  for (int i = 0; i < q; i++) cin >> T[i];

  // main part
  for (int i = 0; i < q; i++) {
    if (binarySearch(S, n, T[i]) != -1) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
