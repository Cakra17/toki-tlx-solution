#include <iostream>

bool check(std::string A, std::string B) {
  int front_match = 0, rear_match = 0, breakpoint = 0;

  for (int i = 0; i < B.size(); i++) {
    if (A[i] == B[i]) {
      front_match++;
    } else {
      breakpoint = i;
      break;
    }
  }

  int j = B.size()-1;
  for (int i = A.size()-1; i>breakpoint; i--) {
    if (A[i] == B[j]) {
      rear_match++;
    } else {
      break;
    }
    j--;
    if (j<0) break;
  }

  if ((front_match + rear_match) == B.size()) return true;

  if (front_match == B.size()) return true;
  return false;
}

int main() {
  std::string A, B; std::cin >> A >> B;
  int diff = 0; 

  if (A.size() - B.size() == 1) {
    if (check(A, B)) {
      std::cout << "Tentu saja bisa!" << std::endl;
    } else {
      std::cout << "Wah, tidak bisa :(" << std::endl;
    }

  } else {
    std::cout << "Wah, tidak bisa :(" << std::endl;
  }

  return 0;
}
