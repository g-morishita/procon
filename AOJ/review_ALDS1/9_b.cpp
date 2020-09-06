#include <iostream>
using namespace std;

const int MAX = 500005;

void maxHeapify(int A[], int n, int i) {
  int left_i = 2 * i;
  int right_i = 2 * i + 1;
  int largest_i {i};

  if (left_i <= n && A[left_i] > A[i]) {
    largest_i = left_i;
  }

  if (right_i <= n && A[right_i] > A[largest_i]) {
    largest_i = right_i;
  }

  if (largest_i != i) {
    int tmp = A[i];
    A[i] = A[largest_i];
    A[largest_i] = tmp;
    maxHeapify(A, n, largest_i);
  }
}

void buildMaxHeap(int A[], int n) {
  for (int i = n / 2; i >= 1; i--) {
    maxHeapify(A, n, i);
  }
}

int main() {
  int A[MAX];
  int h {0};
  cin >> h;
  for (int i = 1; i <= h; i++) cin >> A[i];
  buildMaxHeap(A, h+1);
  for (int i = 1; i <= h; i++) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
