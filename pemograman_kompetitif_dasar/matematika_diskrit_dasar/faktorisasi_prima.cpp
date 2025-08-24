#include<iostream>
#include<vector>

typedef std::vector<std::pair<int, int>> vpair;

void getPower(vpair &a, int &n, int &p) {
  int power = 0;
  int cal = 1;
  for (int i = p; n % i == 0; i *= p) {
    cal = i;
    power++;
  }
  n /= cal;
  std::pair<int, int> res(p,power);
  a.push_back(res);
}

int main() {
  int n; std::cin >> n;
  vpair basis;
  int pembagi = 2;
  while (n != 1) {
    if (n % pembagi == 0) {
      getPower(basis, n, pembagi);
    }
    pembagi++;
  }

  for (size_t i = 0; i < basis.size(); i++) {
    if (basis[i].second == 1) {
      std::cout << basis[i].first;
    } else {
      std::cout << basis[i].first << "^" << basis[i].second;
    }

    if (i != basis.size() - 1) std::cout << " x ";
  }
  std::cout << std::endl;
  return 0;
}
