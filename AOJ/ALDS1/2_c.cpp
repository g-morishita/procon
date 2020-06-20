#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vec(vector<string> v) {
  int v_size = v.size();
  for (int i = 0; i < v_size; i++) {
    if (i != v_size - 1) {
      cout << v.at(i) << " ";
    } else {
      cout << v.at(i) << "\n";
    }
  }
}


void bubble_sort(vector<string>& a) {
  int a_size = a.size();
  for (int i = 0; i < a_size; i++) {
    for (int j = a_size-1; j > i; j--) {
      int current_value = (a.at(j)[1]) - 48;
      int prev_value = (a.at(j-1)[1]) - 48;
      if (current_value < prev_value) {
        string tmp = a.at(j);
        a.at(j) = a.at(j-1);
        a.at(j-1) = tmp;
      }
    }
  }
}

void insertion_sort(vector<string>& a) {
  int a_size = a.size();
  for (int i = 0; i < a_size; i++) {
    int min_idx = i;
    for (int j = i + 1; j < a_size; j++) {
      if (a.at(min_idx)[1] > a.at(j)[1]) {
        min_idx = j;
      }
    }
    string tmp;
    tmp = a.at(i);
    a.at(i) = a.at(min_idx);
    a.at(min_idx) = tmp;
  }
}

int main() {
  vector<string> cards;
  vector<string> copied_cards;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    cards.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    copied_cards.push_back(cards.at(i));
  }

  bubble_sort(cards);
  insertion_sort(copied_cards);
  print_vec(cards);
  bool is_stable = true;
  for (int i = 0; i < n; i++) {
    if (cards.at(i) != copied_cards.at(i)) {
      is_stable = false;
      break;
    }
  }
  cout << "Stable\n";
  print_vec(copied_cards);
  if (is_stable) {
    cout << "Stable\n";
  } else {
    cout << "Not Stable\n";
  }
}
