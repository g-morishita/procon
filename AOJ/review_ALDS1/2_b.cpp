#include <iostream>
using namespace std;

const int MAX = 105;
const int INFTY = (1 << 30);
int A[MAX], n, cnt;

void insertion_sort() {
  for (int i = 0; i < n; i++) {
    int mini {i}; 
    bool is_swap = false;
    for (int j = i; j < n; j++) {
      if (A[mini] > A[j]) {
        is_swap = true;
        mini = j;
      }
    }
    int tmp = A[mini];
    A[mini] = A[i];
    A[i] = tmp;
    if (is_swap) cnt++;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  insertion_sort();

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << A[i];
    } else {
      cout << " " << A[i];
    }
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
