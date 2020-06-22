#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt {0};
void insertion_sort(vector<int>& A, int n, int g) {
  for (int i = g; i < n; i++) {
    int key = A.at(i);
    int j = i - g;
    while (j >= 0 && A.at(j) > key) {
      A.at(j+g) = A.at(j);
      j -= g;
      cnt++;
    }
    A.at(j+g) = key;
  }
}

void shell_sort(vector<int>& A, int n) {
  cnt = 0;
  vector<int> G;
  int r = 1;
  while (r <= n) {
    G.push_back(r);
    r *= 2;
  }
  cout << G.size() << endl;
  reverse(G.begin(), G.end());
  for (int i = 0; i < G.size(); i++) {
    cout << G.at(i) << " ";
  }
  cout << endl;

  for (int g : G) {
    insertion_sort(A, n, g);
  }
}

int main() {
  int n;
  vector<int> A;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }
  shell_sort(A, A.size());
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << A.at(i) <<endl;
  }
}
