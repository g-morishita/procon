#include <iostream>
using namespace std;

const int MAX = 200000;
const int MAX_V = 1000000001;
int L[MAX];
int R[MAX];
int A[MAX];
long long num_inversions;

long long merge(int a[], int left, int right, int mid) {
  long long cnt {0};
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) {
    L[i] = A[i+left];
  }

  for (int i = 0; i < n2; i++) {
    R[i] = A[i+mid];
  }
  L[n1] = R[n2] = MAX_V;

  int j {0}, k{0};
  for (int i = left; i < right; i++) {
    if (R[j] <= L[k]) {
      A[i] = R[j];
      cnt += n1 - k;
      j++;
    } else {
      A[i] = L[k];
      k++;
    }
  }
  return cnt;
}

long long mergeSort(int a[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    long long v1 = mergeSort(a, left, mid);
    long long v2 = mergeSort(a, mid, right);
    long long v3 = merge(a, left, right, mid);
    return v1 + v2 + v3;
  } else {
    return 0;
  }
}

int main() {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  long long ans = mergeSort(A, 0, n);
  cout << ans << endl;

  return 0;
}
