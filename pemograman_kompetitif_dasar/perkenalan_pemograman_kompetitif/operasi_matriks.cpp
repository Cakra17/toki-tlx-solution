#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <string>

typedef std::vector<std::vector<int>> Array;
typedef std::string String;

int n, m;

void swap_horizontally(Array &arr) {
  for (int i = 0; i < n/2; i++) {
    std::swap(arr[i], arr[n - i - 1]);
  }
}

void swap_vertically(Array &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::reverse(arr[i].begin(), arr[i].end());
  }
}

void rotate_90(Array &arr) {
  Array temp(m, std::vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = arr[n - j - 1][i];
    }
  } 
  arr = temp;
  std::swap(n,m);
}

void matrix_ops(Array &arr, String ops) {
  if (ops == "_") {
    swap_horizontally(arr);
  } else if (ops == "|") {
    swap_vertically(arr) ;
  } else if (ops == "90") {
    rotate_90(arr);
  } else if (ops == "180") {
    swap_vertically(arr);
    swap_horizontally(arr);
  } else if (ops == "270") {
    swap_vertically(arr);
    swap_horizontally(arr);
    rotate_90(arr);
  } else {
    std::cout << "Invalid operation" << std::endl;
  }
}

int main() {
  // takes rows, cols, number of operations
  int x;std::cin >> n >> m >> x;
  Array arr(n, std::vector<int>(m));

  // takes arrray input
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> arr[i][j];
    }
  }

  // takes operations
  for (int i = 0; i < x; i++) {
    String ops; std::cin >> ops;
    matrix_ops(arr, ops);
  }

  // print result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
