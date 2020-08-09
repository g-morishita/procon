#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000005;
int cnt;

void generalizedInsertionSort(int A[], int n, int gap) {
  for (int i = gap; i < n; i++) {
    int key = A[i];
    int j = i - gap;
    while ((j >= 0) && (key < A[j])) {
      A[j+gap] = A[j];
      j -= gap;
      cnt++;
    }
    A[j+gap] = key;
  }
}

void shellSort(int A[], int n) {

  vector<int> G;
  // generate a gap sequence
  int gap {1};
  while (gap <= n) {
    G.push_back(gap);
    gap = 3 * gap + 1;
  }

  for (int i = G.size() - 1; i >= 0; i--) {
    generalizedInsertionSort(A, n, G[i]);
  }

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << G[i] << " ";
  }
  cout << endl;
}

int main() {
  int A[MAX];
  int n {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  shellSort(A, n);

  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }
}
