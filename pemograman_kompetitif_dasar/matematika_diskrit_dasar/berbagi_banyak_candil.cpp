#include <iostream>
typedef long long ll;

int main() {
  ll B, C, D;
  std::cin >> B >> C >> D;

  ll counter = 0;
  ll N = C-D;

  if (C == D) {
    if (C < B) counter = B - C; 
    std::cout << counter << std::endl;
    return 0;
  }

  for (ll i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      ll pair = N / i;
      if (i > D && i <= B) counter++;
      if (pair > D && pair <= B && pair != i) counter++;
    }
  }

  std::cout << counter << std::endl;
  return 0;
}
