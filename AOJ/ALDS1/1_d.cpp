#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> R;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    R.push_back(tmp);
  }

  int ans = R.at(1) - R.at(0);
  int min = ans > 0 ? R.at(0) : R.at(1);

  for (int i = 2; i < n; i++) {
    if (min > R.at(i)) {
      min = R.at(i);
    }
    if (R.at(i) >= R.at(i-1)) {
      int tmp_ans = R.at(i) - min;
      if (tmp_ans > ans) {
        ans = tmp_ans;
      }
    }
  }
  cout << ans << endl;
}
