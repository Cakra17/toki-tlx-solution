#include<iostream>
typedef long long ll;

int main() {
  int n; std::cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y; std::cin >> x >> y;
  }

  if (n < 3) {
    std::cout << 0 << std::endl;
  } else {
    ll res = (ll)n * (n-1) * (n-2)/ 6;
    std::cout << res << std::endl;
  }
  return 0;
}
