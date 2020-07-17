#include <iostream>
#include <string>
using namespace std;

const int MAX = 2000000;
const int INF = 2000005;
int H;
int A[MAX];

void maxHeapify(int a[], int h, int i) {
  int right_id = 2 * i + 1;
  int left_id = 2 * i;
  int largest_id = i;

  if (right_id <= h) {
    int right_key = a[right_id];
    if (right_key <= a[i]) {
      largest_id = i;
    } else {
      largest_id = right_id;
    }
  }

  if (left_id <= h) {
    int left_key = a[left_id];
    if (left_key > a[largest_id]) {
      largest_id = left_id;
    }
  }
  if (largest_id != i) {
    int tmp = a[i];
    a[i] = a[largest_id];
    a[largest_id] = tmp;
    maxHeapify(A, h, largest_id);
  }
}

void heapIncreaseKey(int k, int i) {
  if (k < A[i]) return;
  A[i] = k;
  while (i > 1 && A[(i / 2)] < A[i]) {
    int tmp = A[i];
    A[i] = A[i/2];
    A[i/2] = tmp;
    i = i/2;
  }
}

void insert(int k) {
  H++;
  A[H] = -INF;
  heapIncreaseKey(k, H);
}

int heapExtractMax() {
  int m = A[1];
  A[1] = A[H];
  H--;
  maxHeapify(A, H, 1);
  return m;
}

int main() {
  string op;
  int k;
  cin >> op;
  while (op != "end") {
    if (op == "insert") {
      cin >> k;
      insert(k);
    }
    if (op == "extract") {
      cout << heapExtractMax() << endl;
    }
    cin >> op;
  }
  return 0;
}
