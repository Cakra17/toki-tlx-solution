#include<iostream>
typedef long long ll;

ll mod = 1000000007;

int main() {
  int n, a, b; std::cin >> n >> a >> b;
  ll C[n+1][n+1];
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      if (j == i) {
        C[i][j] = 1;
      } else {
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
      }
    }
  }
  ll result = 0;
  for (int i = a; i <= b; ++i) {
    result = (result + C[n][i]) % mod;
  }
  std::cout << result << std::endl;
  return 0;
}
