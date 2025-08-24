#include<iostream>

std::string quitePrime(int num) {
  int i = 1;
  int counter = 0;
  while (i * i <= num) {
    if (num % i == 0) {
      counter++;
    }

    if (counter > 2) {
      return "BUKAN";
    }
    i++;
  }
  return "YA";
}

int main() {
  int n; std::cin >> n;
  int arr[n];
  for (size_t i = 0; i < n; i++)
  {
    int x; std::cin >> x;
    arr[i] = x;
  }

  for (const int& a:arr) {
    std::cout << quitePrime(a) << std::endl;
  }
  return 0;
}
