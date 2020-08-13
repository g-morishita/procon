#include <iostream>
#include <string>
using namespace std;

const int M = 1046527;
string H[M];

int getChar(char ch) {
  if (ch == 'A') return 1;
  if (ch == 'C') return 2;
  if (ch == 'G') return 3;
  if (ch == 'T') return 4;
  return 0;
}

long long getKey(string str) {
  long long sum {0}, p {1};
  for (char ch : str) {
    sum += p * (getChar(ch));
    p *= 5;
  }

  return sum;
}

int h1(int key) {
  return key % M;
}

int h2(int key) {
  return 1 + (key % (M-1));
}

bool find(string str) {
  long long key, i {0};
  key = getKey(str);
  while (true) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H[h] == str) {
      return true;
    } else if (H[h].size() == 0) {
      return false;
    }
    i++;
  }
  return false;
}

void insert(string str) {
  long long key, i {0}, h;
  key = getKey(str);
  while (true) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h] == str) return;
    else if (H[h].size() == 0) {
      H[h] = str;
      return;
    }
    i++;
  }
}

int main() {
  int n;
  string command, str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> command >> str;
    if (command == "insert") {
      insert(str);
    }
    if (command == "find") {
      if (find(str)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
