#include <iostream>
using namespace std;

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  int tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i + 1;
}


int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  int i = partition(A, 0, n-1);
  for (int j = 0;  j < n; j++) {
    if (j) cout << " ";
    if (j == i) {
      cout << "[" << A[j] << "]";
    } else {
      cout << A[j];
    }
  }
  cout << endl;
}
