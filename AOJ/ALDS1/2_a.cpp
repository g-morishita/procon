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
  int n;
  cin >> n;
  vector<int> A;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (A.at(j) < A.at(j-1)) {
        int tmp = A.at(j);
        A.at(j) = A.at(j-1);
        A.at(j-1) = tmp;
        swap_count++;
      }
    }
  }
  print_vec(A);
  cout << swap_count << endl;
}
