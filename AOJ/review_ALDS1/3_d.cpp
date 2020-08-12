#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

stack<int> S1;
stack<pair<int, int>> S2;

int main() {
  int area {0}, tmp_area {0};
  int position {0};
  char c;
  while (cin >> c) {
    if (c == '\\') {
      S1.push(position);
    } else if (c == '/' && !S1.empty()) {
      int matching_position = S1.top(); S1.pop();
      area += (position - matching_position);
      tmp_area = position - matching_position;
      if (!S2.empty()) {
        auto prev_pond = S2.top();
        while (prev_pond.first > matching_position) {
          S2.pop();
          tmp_area += prev_pond.second;
          if (S2.empty()) {
            break;
          }
          prev_pond = S2.top();
        }
      }
      S2.push(make_pair(matching_position, tmp_area));
    }
    position++;
    if (c == 'q') break;
  }

  cout << area << endl;
  cout << S2.size();
  vector<int> ans;
  while (!S2.empty()) {
    ans.push_back(S2.top().second);
    S2.pop();
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << " " << ans.at(i);
  }
  cout << endl;
}
