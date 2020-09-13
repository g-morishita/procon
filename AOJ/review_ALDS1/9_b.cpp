#include <iostream>
using namespace std;

const int MAX = 500005;

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

void maxHeapify(int H[], int h, int r) {
  int largest = r;
  if (left(r) <= h && H[largest] < H[left(r)]) {
    largest = left(r);
  }
  if (right(r) <= h && H[largest] < H[right(r)]) {
    largest = right(r);
  }
  if (largest != r) {
    int tmp = H[r];
    H[r] = H[largest];
    H[largest] = tmp;
    maxHeapify(H, h, largest);
  }
}

void buildHeap(int H[], int h) {
  for (int i = h / 2; i >= 1; i--) {
    maxHeapify(H, h, i);
  }
}

int main() {
  int H[MAX];
  int h;
  cin >> h;
  for (int i = 1; i <= h; i++) cin >> H[i];
  buildHeap(H, h);

  for (int i = 1; i <= h; i++) {
    cout << " " << H[i];
  }
  cout << endl;
}
