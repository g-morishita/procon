#include <iostream>
#include <string>
using namespace std;

const int MAX = 2000005;

void maxHeapify(int Heap[], int &h, int i) {
  int largest = i;
  if (i * 2 <= h && Heap[i * 2] > Heap[largest]) {
    largest = i * 2;
  }
  if (i * 2 + 1 <= h && Heap[i * 2 + 1] > Heap[largest]) {
    largest = i * 2 + 1;
  }
  if (largest != i) {
    int tmp = Heap[i];
    Heap[i] = Heap[largest];
    Heap[largest] = tmp;
    maxHeapify(Heap, h, largest);
  }
}

void insert(int Heap[], int &h, int key) {
  Heap[++h] =  key;
  int i = h;
  while (i > 1 && Heap[i] > Heap[i/2]) {
    int tmp = Heap[i];
    Heap[i] = Heap[i/2];
    Heap[i/2] = tmp;
    i /= 2;
  }
}

int extractMax(int Heap[], int &h) {
  int max = Heap[1];
  Heap[1] = Heap[h];
  h--;
  maxHeapify(Heap, h, 1);

  return max;
}

int main() {
  int Heap[MAX];
  int h {0};

  string s;
  while (cin >> s) {
    if (s == "insert") {
      int key;
      cin >> key;
      insert(Heap, h, key);
    } else if (s == "extract") {
      int m = extractMax(Heap, h);
      cout << m << endl;
    }
    if (s == "end") {
      break;
    }
  }
  return 0;
}
