#include <iostream>
using namespace std;

const int MAX = 100005;

int main() {
  int A[MAX];
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int num_divisions = 1;
  int current_index = 1;
  bool is_increasing = false;
  while (current_index < N) {
    while ((current_index < N) && (A[current_index] == A[current_index - 1])) {
      current_index++;
    }
    while ((current_index < N) &&  (A[current_index] - A[current_index - 1] >= 0)) {
      is_increasing = true;
      current_index++;
    }
    if (!is_increasing) {
      while ((current_index < N) && (A[current_index] - A[current_index - 1] <= 0)) {
        current_index++;
      }
    }
    if (current_index == N) {
      break;
    }
    num_divisions++;
    current_index++;
    is_increasing = false;
  }
  cout << num_divisions << endl;
  return 0;
}
