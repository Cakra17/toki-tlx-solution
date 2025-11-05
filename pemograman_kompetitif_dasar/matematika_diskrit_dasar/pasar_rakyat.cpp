#include <iostream>
#include <cmath>

typedef long long ll ;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int n; std::cin >> n;
  int d[n];
  for (int i = 0; i < n; i++) {
    std::cin >> d[i];
  }
  
  ll res = d[0];
  if (n > 1) {
    for (int i = 1; i < n; i++) {
      res = lcm(res, d[i]);
    }
  } 

  std::cout << res << std::endl;

  return 0;
}
