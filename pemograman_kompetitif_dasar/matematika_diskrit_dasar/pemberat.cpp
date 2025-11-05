#include <iostream>

typedef long long ll;

int main() {
  ll B, K;
  std::cin >> B >> K;

  ll diff = K - B;

  int max_power = 0;
  ll temp = diff;
  while(temp > 1) {
    temp >>= 1;
    max_power++;
  }

  ll cal = diff;
  for (int i = max_power; i >= 0; i--) {
    ll weight = 1LL << i;
    if (cal >= weight) {
      cal -= weight;
      std::cout << weight << std::endl;
    }
  }

  return 0;
}
