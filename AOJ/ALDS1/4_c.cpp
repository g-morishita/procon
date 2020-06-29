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
  else return 0;
}

long long getKey(string str) {
  int sum {0}, p {1};
  for (char c: str) {
    sum += p * getChar(c);
    p *= 5;
  }
  return sum;
}

int hash1(int key) {
  return key % M;
}

int hash2(int key) {
  return 1 + (key % (M-1));
}

int find(string str) {
  long long key {0}, i {0}, h {0};
  key = getKey(str);
  while (true) {
    h = (hash1(key) + i * hash2(key)) % M;
    if (H[h] == str) return 1;
    else if (H[h].empty()) return 0;
    i++;
  }
  return 0;
}

int insert(string str) {
  long long key {0}, i {0}, h {0};
  key = getKey(str);
  while (true) {
    h = (hash1(key) + i * hash2(key)) % M;
    if (str == H[h]) {
      return 1;
    } else if (H[h].empty()) {
      H[h] = str;
      return 0;
    }
    i++;
  }
  return 0;
}

int main() {
  int n {0};
  cin >> n;
  string command, str;
  for (int i = 0; i < n; i++) {
    cin >> command >> str;
    if (command[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
