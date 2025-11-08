#include <iostream>
#include <vector>

typedef long long ll;

ll bin_search(const std::vector<ll>& A, const ll value) {
  ll l = 0, r = A.size();
  ll res;
  while (l <= r) {
    ll mid = l + (r-l)/2;

    if (A[mid] >= value) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return res+1;
}

int main() {
  ll N; std::cin >> N;
  std::vector<ll> A(N);
  int prefix = 0;
  for (int i = 0; i < N; i++) {
    ll a; std::cin>>a;
    A[i] = a + prefix;
    prefix = A[i];
  }

  ll Q; std::cin >> Q;
  std::vector<ll> x(Q);
  for (int i = 0; i < Q; i++) std::cin >> x[i];

  for (const ll& q: x) {
    std::cout << bin_search(A, q) << std::endl;
  }

  return 0;
}
