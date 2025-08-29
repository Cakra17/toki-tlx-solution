#include<iostream>
#include<numeric>
typedef long long ll;

int main() {
  int A, B, C, D;
  std::cin >> A >> B ;
  std::cin >> C >> D;

  ll numerator = 1LL * A * D + 1LL * C * B;
  ll denominator = 1LL * B * D;

  ll g = std::gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;

  std::cout << numerator << " " << denominator << std::endl;
  return 0;
}
