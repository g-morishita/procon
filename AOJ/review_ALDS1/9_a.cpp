#include <iostream>
using namespace std;

const int MAX = 255;
int heap[MAX];

int main() {
  int h;
  cin >> h;
  for (int i = 1; i <= h; i++) cin >> heap[i];
  for (int i = 1; i <= h; i++) {
    cout << "node " << i << ": key = " << heap[i] << ", ";
    if (i != 1) {
      cout << "parent key = " << heap[i/2] << ", ";
    }
    if (h >= 2 * i) {
      cout << "left key = " << heap[2*i] << ", ";
    }
    if (h >= 2 * i + 1) {
      cout << "right key = " << heap[2*i + 1] << ", ";
    }
    cout << endl;
  }
  return 0;
}
