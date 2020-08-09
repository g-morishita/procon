#include <iostream>
#include <string>
using namespace std;

const long long MAX = 500;
string A[MAX];
long long top = 0;

bool isEmpty() {
  return (top == 0);
}

void push(string s) {
  A[++top] = s;
}

string pop() {
  return A[top--];
}

long long add(string s, string t) {
  long long sum = stoll(s) + stoll(t);
  return sum;
}

long long sub(string s, string t) {
  long long diff = stoll(s) - stoll(t);
  return diff;
}

long long mul(string s, string t) {
  long long fac = stoll(s) * stoll(t);
  return fac;
}


int main() {
  string s, t, u;
  while (cin >> s) {
    if (s == "+") {
      t = pop();
      u = pop();
      push(to_string(add(t, u)));
    } else if (s == "-") {
      t = pop();
      u = pop();
      push(to_string(sub(u, t)));
    } else if (s == "*") {
      t = pop();
      u = pop();
      push(to_string(mul(u, t)));
    } else {
      push(s);
    }
  }
  cout << A[top] << endl;
}
