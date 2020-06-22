#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

queue<string> split(const string s, char delim) {
  queue<string> splitted_strs;
  string item;
  for (char ch : s) {
    if (ch == delim) {
      if (!item.empty()) {
        splitted_strs.push(item);
      }
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty()) {
    splitted_strs.push(item);
  }
  return splitted_strs;
}

void calc(string op, stack<string> &st) {
  int op1 = stoi(st.top());
  st.pop();
  int op2 = stoi(st.top());
  st.pop();
  
  if (op == "+") {
    st.push(to_string(op1 + op2));
  } else if (op == "-") {
    st.push(to_string(op2 - op1));
  } else if (op == "*") {
    st.push(to_string(op1 * op2));
  }
}


int main() {
  string s;
  getline(cin, s);
  queue<string> ops;
  ops = split(s, ' ');
  stack<string> st;
  while(!ops.empty()) {
    string op;
    op = ops.front();
    ops.pop();
    if (op == "*" || op == "+" || op == "-") {
      calc(op, st);
    } else {
      st.push(op);
    }
  }
  cout << st.top() << endl;
}
