#include<iostream>
#include<vector>

int main() {
  int x; std::cin>>x;
  std::vector<int> res(x);
  for (int i = 0; i < x; i++) {
    std::cin >> res[i];
  }

  int n = 1100000;
  std::vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  std::vector<int> primeList;

  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primeList.push_back(i);
      if (1LL * i * i <= n) {
        for (int j=i*i; j<=n; j+=i) {
          isPrime[j] = false;
        }
      } 
    }
  }

  for (int i = 0; i < x; ++i) {
    std::cout << primeList.at(res[i]-1) << std::endl;
  }
  return 0;
}
