#include <iostream>
#include <vector>

typedef long long ll;

ll findLastPoint(const std::vector<ll>& A, const ll value) {
  ll l = 0, r = A.size();
  while (l < r) {
    ll mid = l + (r-l)/2;
    if (A[mid] <= value) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  ll N, K; std::cin>> N >> K;
  std::vector<ll> A(N), B(K);
  int prefix = 0;
  for (int i = 0; i < N; i++) {
    ll x ;std::cin >> x;
    A[i] = x + prefix;
    prefix += x;
  }
  for (int i = 0; i < K; i++) std::cin >> B[i];

  for (const auto& b:B) {
    std::cout << findLastPoint(A, b) << std::endl;
  }
  return 0;
}
