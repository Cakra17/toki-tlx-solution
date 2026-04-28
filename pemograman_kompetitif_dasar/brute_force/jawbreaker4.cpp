#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void check(
  std::vector<std::vector<char>> &arr, 
  std::vector<std::vector<int>> &path, 
  int x, int y, int &count, char target) {
  if (path[x][y] == 1 || arr[x][y] == '.') {
    return;
  }

  // mark the path to prevent multiple exploration
  // change the value to '.'  
  // increase the counter  
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


void collapse(std::vector<std::vector<char>> &arr, int N, int M) {
  for (int col = 0; col < N; col++) {
    for (int row = M; row > 0; row--) {
      if (arr[row][col] == '.') {
        for  (int i = row - 1; i >= 0; --i) {
          if (arr[i][col] != '.') {
            std::swap(arr[row][col], arr[i][col]);
            break;
          }
        }
      }
    }
  }
}

int eval(int count) {
  return count * (count - 1);
}

int find_two(
  std::vector<std::vector<char>> &init,
  int M, int N) {
  int longest = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int count = 0;
      std::vector<std::vector<char>> arr = init;
      std::vector<std::vector<int>> path(M, std::vector<int>(N, 0));
      check(arr, path, i, j, count, arr[i][j]);
      if (count <= 1) continue;
      collapse(arr, N, M-1);

      longest = std::max(longest, count);
    }
  }
  return longest;
}

int main() {
  int M, N; std::cin >> M >> N;
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
  std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));

  // loop over all position on matric
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      // if already visited just skip to another position
      if (visited[i][j]) continue;

      int count = 0;
      std::vector<std::vector<char>> arr = init;
      std::vector<std::vector<int>> path(M, std::vector(N, 0)); 
      
      // check for all possible line/combination
      check(arr, path, i, j, count, arr[i][j]);
      
      // mark all visited path when doing check to a global visited state
      for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
          if (path[r][c]) visited[r][c] = true;

      // if count equal or less than 1 which mean it doesn't traverse anywhere
      // just skip the position
      if (count <= 1) continue;

      // perform a collapse for all '.'
      collapse(arr, N, M-1);

      // find another possible line/combination
      int count2 = find_two(arr, M, N);

      // check if the current count is bigger
      if (eval(count) + eval(count2) > longest) {
        longest = eval(count) + eval(count2);
      }
    }
  }

  // print result
  std::cout << longest << std::endl;
  return 0;
}
