#include <iostream>
#include <vector>

std::vector<int> res;
int N, K;

void solve(int depth) {
  if (depth == K) {
    for (auto& a: res) {
      std::cout << a << " ";
    }
    std::cout << std::endl;
    return;
  } else {
    for (int i = res[depth-1]+1; i <= N; i++) {
      res[depth] = i;
      solve(depth + 1);
    }
  } 
}

int main() {
  std::cin >> N >> K;
  res.resize(K,0);
  solve(0);
  return 0;
}
