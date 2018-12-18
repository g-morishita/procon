#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;
  std::cout << S[0] << S.size() - 2 << S[S.size() - 1] << std::endl;

  return 0;
}
