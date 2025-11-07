#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <vector>
typedef long long ll;

int main() {
  ll N; std::cin >> N;
  std::vector<std::string> list(N);
  std::map<int, std::vector<std::string>> strMap;
  size_t longest = 0;
  size_t shortest = N;

  for (int i = 0; i < N; i++) {
    std::cin >> list[i];
    longest = std::max(longest, list[i].size());
    shortest = std::min(shortest, list[i].size());
  }

  std::sort(list.begin(), list.end());

  for (int i = 0; i < list.size(); i++) {
    int size = list[i].size();
    strMap[size].push_back(list[i]);
  }

  std::vector<std::string> res(N);
  for (int i = shortest; i <= longest; i++) {
    if (strMap[i].size() > 0) {
      for (int j = 0; j < strMap[i].size(); j++) {
        res.push_back(strMap[i][j]);
      }
    }
  }

  for (const auto& l : res) {
    std::cout << l << std::endl;
  }
  return 0;
}
