#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  ll N;
  std::cin >> N;
  std::vector<ll> list(N);
  for (int i = 0; i < N; i++) {
    std::cin >> list[i];
  }

  std::sort(list.begin(), list.end());

  float median;
  if (N % 2 == 0) {
    median = ((float)list[N/2] + (float)list[N/2-1])/2;
  } else {
    median = (float)list[N/2];
  }

  printf("%.1f\n", median);
  return 0;
}
