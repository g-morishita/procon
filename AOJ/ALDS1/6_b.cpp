#include <iostream>
using namespace std;

int A[100000];

int partition(int a[], int p, int r) {
  int x = a[r];
  int i = p - 1;
  int tmp {0};
  for (int j = p; j < r; j++) {
    if (a[j] <= x) {
      i++;
      // exchange a[i] and a[j]
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }

  // exchange a[i+1] and a[r]
  tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;
  return i+1;
}

int main() {
  int n {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int key = partition(A, 0, n-1);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    if (i == key) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
  }
  cout << endl;
  return 0;
}
