#include <iostream>
#include <utility>
#include <vector>

void check(
  std::vector<std::vector<char>> &arr, 
  std::vector<std::vector<int>> &path, 
  int x, int y, int &count, char target) {
  if (path[x][y] == 1) {
    return;
  }

  path[x][y] = 1;
  arr[x][y] = '.';
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

void print_result(std::vector<std::vector<char>> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

}

void collapse(std::vector<std::vector<char>> &arr, int col, int size) {
  int idx = size;
  while (idx != 0) {
    if (arr[idx][col] == '.') {
      for  (int i = idx - 1; i >= 0; --i) {
        if (arr[i][col] != '.') {
          std::swap(arr[idx][col], arr[i][col]);
          break;
        }
      }
    }
    idx--;
  }
}

int main() {
  int M, N; std::cin >> M >> N;
  std::vector<std::vector<int>> path(M, std::vector(N, 0));
  std::vector<std::vector<char>> window;
  int longest = 0;

  for (int i = 0; i < M; i++) {
    std::vector<char> temp;
    for (int j = 0; j < N; j++) {
      char a; std::cin >> a;
      temp.push_back(a);
    }
    window.push_back(temp);
  }

  std::vector<std::vector<char>> init = window;
  
  // find the longest streak and change to .
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int count = 0;
      std::vector<std::vector<char>> arr = init;
      check(arr, path, i, j, count, arr[i][j]);
      if (count > longest) {
        longest = count;
        window = arr;
      }
    }
  }

  // collapse
  for (int col = 0; col < N; ++col) {
    collapse(window, col, M-1);
  } 

  // result
  print_result(window);

  return 0;
}
