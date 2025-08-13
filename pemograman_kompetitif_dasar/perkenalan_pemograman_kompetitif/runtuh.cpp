#include<iostream>

int R, C;
char grid[20][8];

int findLastRow() {
  int lastRow = -1;
  for(int row = 0; row < R; row++) {
    bool isFull = true;
    for(int col = 0; col < C; col++) {
      if(grid[row][col] != '1') {
        isFull = false;
        break;
      }
    }
    if(isFull){
      lastRow = row;
      for(int col = 0; col < C; col++) {
        grid[row][col] = '0';
      }
    }
  }
  return lastRow;
}

int findLastRowToFall(int lastRow, int col) {
  for (int row = lastRow; row < R-1; row++) {
    if (grid[row+1][col] == '1')
      return row;
  }
  return R-1;
}

int countBlackPixelsAbove(int lastRow, int col) {
  int res = 0;
  for (int row = 0; row < lastRow; row++) {
    if (grid[row][col] == '1')
      res++;
  }
  return res;
}

void collapse(int blackPixels, int lastRow, int col) {
  for (int row = lastRow; row >= 0; row--) {
    if (row > lastRow - blackPixels) {
      grid[row][col] = '1';
    } else {
      grid[row][col] = '0';
    }
  }
}

int main() {
  std::cin >> R >> C;
  
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      std::cin >> grid[i][j];
    }
  }
  
  int lastRow = findLastRow();
  while(lastRow != -1) {
    for(int col = 0; col < C; col++) {
      int blackPixels = countBlackPixelsAbove(lastRow, col);
      int lastRowToFall = findLastRowToFall(lastRow,col);
      collapse(blackPixels, lastRowToFall, col);
    }
    lastRow = findLastRow();
  }

  std::cout << std::endl;

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      std::cout << grid[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
