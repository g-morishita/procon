#include <iostream>
using namespace std;

const static int MAX = 100;
int A[MAX], n;

void print_array() {
  cout << A[0];
  for (int i = 1; i < n; i++) {
    cout << " " << A[i];
  }
  cout << endl;
}

void insert_sort() {
  print_array();
  for (int i = 1; i< n; i++) {
    int key = A[i];
    int j = i -1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    print_array();
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  insert_sort();
}
