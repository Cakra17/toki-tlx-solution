#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  int N; std::cin >> N;
  std::vector<ll> list(N);
  int counter = 0;

  for (int i = 0; i < N; i++) std::cin >> list[i];

  for (int i = 0; i < N-1;  i++) {
    for (int j = 0; j < N-i-1; j++) {
      if (list[j] > list[j+1]) {
        ll temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
        counter++;;
      }
    }
  }

  std::cout << counter << std::endl;

  return 0;
}
