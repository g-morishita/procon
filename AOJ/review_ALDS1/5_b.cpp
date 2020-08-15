#include <iostream>
using namespace std;

const int INFTY = (1 << 30);
const int MAX = 500000;
int cnt;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];

  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1] = R[n2] = INFTY;
  int l_i {0}, r_i {0};
  for (int i = left; i < right; i++) {
    cnt++;
    if (L[l_i] < R[r_i]) {
      A[i] = L[l_i];
      l_i++;
    } else {
      A[i] = R[r_i];
      r_i++;
    }
  }
}


void mergeSort(int A[], int left, int right) {
  int mid = (right + left) / 2;
  if (left + 1 < right) {
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n, A[MAX];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  mergeSort(A, 0, n);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl << cnt << endl;
}
