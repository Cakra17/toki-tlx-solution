#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;

int main() {
  ll N, B;
  std::cin >> N >> B;

  std::string res;
  while (N > 0) {
    ll digit = N % B;
    N /= B;
    res += std::to_string(digit);
  }
  std::reverse(res.begin(), res.end());
  std::cout << res << std::endl;
  return 0;
}
