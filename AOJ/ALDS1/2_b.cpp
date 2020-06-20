#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int> v) {
  int v_size = v.size();
  for (int i = 0; i < v_size; i++) {
    if (i != v_size - 1) {
      cout << v.at(i)<< " ";
    } else {
      cout << v.at(i) << endl;
    }
  }
}

int main() {
  int swap_count {0};
  int n ;
  cin >> n;
  vector<int> A;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    int min_idx = i;
    for (int j = i; j < n; j++) {
      if (A.at(min_idx) > A.at(j)) {
        min_idx = j;
      }
    }
    if (i != min_idx) {
      int tmp = A.at(min_idx);
      A.at(min_idx) = A.at(i);
      A.at(i) = tmp;
      swap_count++;
    }
  }
  print_vec(A);
  cout << swap_count << endl;
}
