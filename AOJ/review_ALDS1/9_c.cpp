#include <iostream>
#include <string>
using namespace std;

const int MAX = 2000005;
const int INFTY = (1 << 30);
int H;

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

void heapIncreaseKey(int A[], int i, int key) {
  A[i] = key;
  while (i > 1 && A[i/2] < A[i]) {
    int tmp = A[i];
    A[i] = A[i/2];
    A[i/2] = tmp;
    i = i/2;
  }
}

int main() {
  int A[MAX];

  string command;
  while (cin >> command) {
    if (command == "insert") {
      int key;
      cin >> key;
      H++;
      A[H] = -INFTY;
      heapIncreaseKey(A, H, key);
    }

    if (command == "extract") {
      cout << A[1] << endl;
      A[1] = A[H];
      H--;
      maxHeapify(A, H, 1);
    }
    
    if (command == "end") {
      break;
    }
  }
  return 0;
}
