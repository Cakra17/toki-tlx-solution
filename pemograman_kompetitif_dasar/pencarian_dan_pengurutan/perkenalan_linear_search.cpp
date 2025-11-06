#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  ll N, X;
  std::cin >> N >> X;
  std::vector<ll> arr(N);

  for (int i = 0; i < arr.size(); i++) {
    std::cin >> arr[i];
  }

  ll lowest = 0;
  ll curr = std::abs(X-arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    ll cal = std::abs(X-arr[i]);
    if (cal < curr) {
      curr = cal;
      lowest = i;
    } else if (cal == curr) {
      lowest = arr[lowest] > arr[i] ? i : lowest;
      curr = std::abs(X-arr[lowest]);
    }
  }
  std::cout << arr[lowest] << std::endl;


  return 0;
}
