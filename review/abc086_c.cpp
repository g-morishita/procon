#include <iostream>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

std::function<bool(std::pair<int, int>, std::pair<int, int>)> compFunctor = [](std::pair<int, int> elem1, std::pair<int, int> elem2)
{
  return elem1.second < elem2.second;
};

int main() 
{
  std::map<int, int> m;
  int n, k;
  std::cin >> n >> k;
  for ( int i = 0; i < n; i++ ) {
    int a;
    std::cin >> a;
    m[a]++;
  }
}
