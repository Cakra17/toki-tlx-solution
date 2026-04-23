#include <iostream>
#include <vector>

void check(
  std::vector<std::vector<int>> &arr, 
  std::vector<std::vector<int>> &path, 
  int x, int y, int &count, int target) {
  if (path[x][y] == 1) {
    return;
  }

  path[x][y] = 1;
  count++;

  // check top
  if (x > 0 && arr[x-1][y] == target && path[x-1][y] == 0) {
    check(arr, path, x-1, y, count, target);
  }

  // check bot
  if (arr.size() - 1 - x > 0 && arr[x+1][y] == target && path[x+1][y] == 0) {
    check(arr, path, x+1, y, count, target);
  }

  // check left
  if (y > 0 && arr[x][y-1] == target && path[x][y-1] == 0) {
    check(arr, path, x, y-1, count, target);
  }

  // check right
  if (arr[0].size() - 1 - y > 0 && arr[x][y+1] == target && path[x][y+1] == 0) {
    check(arr, path, x, y+1, count, target);
  }

  return;
}

int eval(int count) {
  return count * (count - 1);
}

int main() {
  int M, N; std::cin >> M >> N;
  std::vector<std::vector<int>> 
    arr(M, std::vector(N, 0)), path(M, std::vector(N, 0));
  int val = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> arr[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (path[i][j] == 1) {
        continue;
      }
      int count = 0;
      check(arr, path, i, j, count, arr[i][j]);
      val = std::max(count, val);
    }
  }

  std::cout << eval(val) << std::endl;

  return 0;
}
