#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
  std::string s; std::cin >> s;

  int N = ceil(sqrt(s.length()));
  int row = 0;
  std::string arr[N]; std::string tmp;

  for (int i = 0; i < N * N; i++) {
    bool threshold = i > s.length() - 1;
    
    if (!threshold) {
      tmp += s[i];
    } else {
      tmp += ".";
    }

    if (row % 2 == 0 && tmp.length() == N) {
      arr[row] = tmp;
      tmp.clear();
      row++;
    } else if (row % 2 != 0 && tmp.length() == N) {
      std::reverse(tmp.begin(), tmp.end());
      arr[row] = tmp;
      tmp.clear();
      row++;
    }
  }

  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << std::endl;
  }

  return 0;
}
