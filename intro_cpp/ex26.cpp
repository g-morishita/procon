#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<char, int> variable_table;
  map<char, vector<int>> vector_table;

  for (int i = 0; i < N; i++) {
    cerr << i << endl;;
    string s;
    cin >> s;

    if (s == "int") {
      cerr << s << endl;;
      int result {0};
      char var;
      cin >> var;
      char op_term;
      char int_term;
      cin >> op_term;
      bool is_int = true;
      while (op_term != ';') {
        if (is_int) {
          cin >> int_term;

          if (!isdigit(int_term)) {
            int_term = char(variable_table[int_term] + 48);
          }

          if (op_term == '+' || op_term == '=') {
            result += int_term - 48;
          } else if (op_term == '-') {
            result -= int_term - 48;
          }
          is_int = false;
        } else {
          cin >> op_term;
          is_int = true;
        }
      }
      variable_table[var] = result;
    }
    if (s == "print_int") {
      cerr << s << endl;;
      int result {0};
      char op_term {};
      char int_term;
      bool is_int = true;
      bool is_first = true;
      while (op_term != ';') {
        if (is_int) {
          cin >> int_term;

          if (!isdigit(int_term)) {
            int_term = char(variable_table[int_term] + 48);
          }

          if (op_term == '+' || is_first) {
            cerr << int_term << endl;
            result += int_term - 48;
            is_first = false;
          } else if (op_term == '-') {
            cerr << int_term << endl;
            result -= (int_term - 48);
          }
          is_int = false;
        } else {
          cin >> op_term;
          is_int = true;
        }
      }
      cout << result << endl;
    }

    if (s == "vec") {
      vector<int> result;
      char var;
      cin >> var;
      char op_term;
      cin >> op_term;
      char int_term;
      while (op_term != ';') {
        bool is_first = true;
        char c;
        cin >> c;
        cerr << "c:" << c << endl;
        vector<int> tmp_v;
        if (c == '[') {
          bool is_int = true;
          while (c != ']') {
            if (is_int) {
              cin >> int_term;
              if (!isdigit(int_term)) {
                int_term = char(variable_table[int_term] + 48);
              }
              if (is_first) {
                result.push_back(int_term - 48);
                is_first = false;
              } else {
                tmp_v.push_back(int_term - 48);
              }
              is_int = false;
            } else {
              cin >> c;
              is_int = true;
            }
          }
        } else {
          for (int el : vector_table[c]) {
            if (is_first) {
              result.push_back(el);
              is_first = false;
            } else {
              tmp_v.push_back(el);
            }
          }
        }
        if (op_term == '+') {
          for (int i = 0; i < result.size(); i++) {
            result.at(i) += tmp_v.at(i);
          }
        } else if (op_term == '-') {
          for (int i = 0; i < result.size(); i++) {
            result.at(i) -= tmp_v.at(i);
          }
        }
        cin >> op_term;
        cerr << op_term << endl;
      }
      vector_table[var] = result;
      for (int el : vector_table[var]) {
        cerr << el << endl;
      }
    }
  }
}
