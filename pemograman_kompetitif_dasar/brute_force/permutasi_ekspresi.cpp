#include <iostream>
#include <set>
#include <sstream>
#include <string>

typedef long long ll ;

std::set<ll> ans;

ll to_ll(std::string s) {
  std::stringstream ss (s);
  ll res; ss >> res;
  return res;
}

void solve(std::string s, int pos, ll current_value) {
  if (pos == s.size()) {
    ans.insert(current_value);
    return;
  }

  for (int i = pos+1; i <= s.size(); i++) {
    ll segment = to_ll(s.substr(pos, i - pos));
    solve(s, i, current_value + segment);
    solve(s, i, current_value - segment);
  }
}

int main() {
  std::string s; std::cin >> s;
  
  for (int i = 1; i <= s.size(); i++) {
    ll first_segment = to_ll(s.substr(0, i));
    solve(s, i, first_segment);
  }
  
  std::cout << ans.size() << std::endl;
  return 0;
}
