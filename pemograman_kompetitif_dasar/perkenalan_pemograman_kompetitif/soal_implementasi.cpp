#include <iostream>

int main() {
  int x, y; std::cin >> x >> y;
  int arr[x][y];
  int res[y][x];
  
  // take input
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      std::cin >> arr[i][j];
    }
  }
  
  // swap between cols and rows
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      res[j][i] = arr[x - 1 - i][j];
      std::cout << res[j][i] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
