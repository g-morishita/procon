#include <iostream>
using namespace std;

const int MAX = 105;
int n, cnt, A[MAX];

void print_array() {
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << A[i];
    } else {
      cout << " " << A[i];
    }
  }
  cout << endl;
}

void bubble_sort() {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (A[i] < A[i-1]) {
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flag = true;
        cnt++;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  bubble_sort();
  print_array();
  cout << cnt << endl;
}
