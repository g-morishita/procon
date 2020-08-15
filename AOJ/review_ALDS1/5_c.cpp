#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

double th = M_PI * 60.0 / 180.0;

void koch(int d, pair<double, double> p1, pair<double, double> p2) {
  if (d == 0) return;

  pair<double, double> s = make_pair(((2.0 * p1.first) + (1.0 * p2.first)) / 3.0, ((2.0 * p1.second) + (1.0 * p2.second)) / 3.0);
  pair<double, double> t = make_pair(((1.0 * p1.first) + (2.0 * p2.first)) / 3.0, ((1.0 * p1.second) + (2.0 * p2.second)) / 3.0);
  pair<double, double> u;
  u.first = s.first + (t.first - s.first) * cos(th) - (t.second - s.second) * sin(th);
  u.second = s.second + (t.first - s.first) * sin(th) + (t.second - s.second) * cos(th);

  koch(d-1, p1, s);
  cout << s.first << " " << s.second << endl;
  koch(d-1, s, u);
  cout << u.first << " " << u.second << endl;
  koch(d-1, u, t);
  cout << t.first << " " << t.second << endl;
  koch(d-1, t, p2);
}

int main() {
  int n;
  cin >> n;

  pair<double, double> a = make_pair(0.0, 0.0);
  pair<double, double> b = make_pair(100.0, 0.0);
  cout << a.first << " " << a.second << endl;
  koch(n, a, b);
  cout << b.first << " " << b.second << endl;
  return 0;
}
