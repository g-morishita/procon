#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

double th = M_PI * 60.0 / 180.0;

void koch(int d, pair<double, double> p1, pair<double, double> p2) {
  if (d == 0) {
    return;
  }

  pair<double, double> s, u, t;
  s.first = p1.first * 2.0 / 3.0 + p2.first / 3.0;
  s.second = p1.second * 2.0 / 3.0 + p2.second / 3.0;

  t.first = p2.first * 2.0 / 3.0 + p1.first / 3.0;
  t.second = p2.second * 2.0 / 3.0 + p1.second / 3.0;

  u.first = (t.first - s.first) * cos(th) - (t.second - s.second) * sin(th) + s.first;
  u.second = (t.first - s.first) * sin(th) + (t.second - s.second) * cos(th) + s.second;

  koch(d-1, p1, s);
  cout << s.first << " " << s.second << endl;
  koch(d-1, s, u);
  cout << u.first << " " << u.second << endl;
  koch(d-1, u, t);
  cout << t.first << " " << t.second << endl;
  koch(d-1, t, p2);
}

int main() {
  pair<double, double> p1, p2;
  int n;
  cin >> n;

  p1.first = 0.0;
  p1.second = 0.0;
  p2.first = 100.0;
  p2.second = 0.0;

  cout << p1.first << " " << p1.second << endl;
  koch(n, p1, p2);
  cout << p2.first << " " << p2.second << endl;

  return 0;
}
