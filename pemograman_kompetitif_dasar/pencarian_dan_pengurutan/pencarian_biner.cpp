#include <iostream>
#include <vector>

typedef long long ll;

ll lower_bound(const std::vector<ll>& list, const ll value) {
  ll l = 0, r = list.size();
  while(l < r) {
    ll mid = l + (r-l)/2;
    if (list[mid] <= value) {
      l = mid+1;
    } else {
      r = mid;
    }
  }
  return l;
}

ll upper_bound(const std::vector<ll>& list, const ll value) {
  ll l = 0, r = list.size();
  while(l < r) {
    ll mid = l + (r-l)/2;
    if (list[mid] <= value) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}


int main() {
  ll N; std::cin >> N;
  std::vector<ll> list(N);
  for (int i = 0; i < N; i++) std::cin >> list[i];

  ll Q; std::cin >> Q;
  std::vector<std::pair<ll, ll>> listQ(Q);
  for (int i = 0; i < Q; i++) {
    ll x, y; std::cin >> x >> y;
    listQ[i] = std::make_pair(x, y);
  }

  for (const auto& q : listQ) {
    std::cout << (upper_bound(list, q.second) - lower_bound(list, q.first)) << std::endl;
  }

  return 0;
}
