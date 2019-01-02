#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int a[N];
  int v[N] = {0};
  int i = 0;
  v[i]++;
  int cnt = 0;
  for ( int i = 0; i < N; i++ ) std::cin >> a[i];

  bool can = false;
  while(true) {
    std::cerr << "i: " << i << std::endl;
    std::cerr << "a[" << i << "] " << a[i] << std::endl;
    cnt++;
    i = a[i] - 1;
    if ( v[i] == 1 ) {
      break;
    }
    v[i]++;

    if ( i == 1 ) {
      can = true;
      break;
    }
  }
  
  std::cout << (can ? cnt : -1) << std::endl;
  return 0;
}
