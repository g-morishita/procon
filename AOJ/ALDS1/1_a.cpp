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
  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  print_vec(A);
  for (int i = 1; i < N; i++) {
    int key = A.at(i);
    int j = i - 1;
    while (j >= 0 && A.at(j) > key) {
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = key;
    print_vec(A);
  }
}
