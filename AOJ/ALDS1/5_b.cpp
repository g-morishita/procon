#include <iostream>
using namespace std;

const int SENTINEL = 2000000000;
const int MAX = 500000;
int L[MAX];
int R[MAX];
int cnt;

void merge(int A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;

  // create new arrays L, R
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }

  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  // SENTINEL
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  int i {0}, j {0};
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right) {
  if ((left + 1) < right) {
    int mid = (right + left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  mergeSort(A, 0, n);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl << cnt << endl;

  return 0;
}
