#include <iostream>
#include <utility>
using namespace std;

const int MAX = 40;

void print_array(pair<char, int> A[], int n) {
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << A[i].first << A[i].second;
    } else {
      cout << " " << A[i].first << A[i].second;
    }
  }
  cout << endl;
}

bool isStable(pair<char, int> A1[], pair<char, int> A2[], int n) {
  bool is_stable = true;
  for (int i = 0; i < n; i++) {
    if (A1[i].first != A2[i].first) {
      is_stable = false;
    }
  }
  return is_stable;
}

void bubble_sort(pair<char, int> A[], int n) {
  for (int i = 0; i < n; i++) {
    bool is_sorted = true;
    for (int j = n - 1; j >= i; j--) {
      
      if (A[j].second < A[j-1].second) {
        is_sorted = false;
        auto tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
      }
    }
    if (is_sorted) {
      break;
    }
  }
  print_array(A, n);
  cout  << "Stable" << endl;
}

void selection_sort(pair<char, int> A[], int n) {
  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i; j < n; j++) {
      if (A[j].second < A[mini].second) {
        mini = j;
      }
    }
    auto tmp = A[mini];
    A[mini] = A[i];
    A[i] = tmp;
  }
  print_array(A, n);
}

int main() {
  pair<char, int> C1[MAX], C2[MAX];
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> C1[i].first >> C1[i].second;
  }

  for (int i = 0; i < n; i++) {
    C2[i] = C1[i];
  }
  bubble_sort(C1, n);
  selection_sort(C2, n);
  if (isStable(C1, C2, n)) {
    cout << "Stable";
  } else {
    cout << "Not stable";
  }
  cout << endl;

  return 0;
}
