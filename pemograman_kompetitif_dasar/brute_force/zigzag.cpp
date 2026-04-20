#include <iostream>
#include <string>
#include <algorithm>

bool is_zigzag(std::string s)
{
  bool isValid = true;  
  int i = 0;
  do
  {
    if ((int)s[i] < (int)s[i+1] && (int)s[i+2] < (int)s[i+1]) {
      isValid = true;
    } else if ((int)s[i] > (int)s[i+1] && (int)s[i+2] > (int)s[i+1]) {
      isValid = true;
    } else {
      return false;
    }
    i += 1;
  } while(i <= s.size()-1 - 2);
  
  return isValid;
}

// void permute(std::string a, int l, int r) 
// { 
//   if (l == r) 
//   {
//     if (a.size() < 3) {
//       std::cout << a << std::endl;
//     } else if (is_zigzag(a)) {
//       std::cout << a << std::endl;
//     }
//   }
//   else
//   { 
//     for (int i = l; i <= r; i++) 
//     { 
//       std::swap(a[l], a[i]); 
//
//       permute(a, l+1, r); 
//
//       std::swap(a[l], a[i]); 
//     } 
//   } 
// }

int main() 
{
  int N; std::cin >> N;
  std::string s;

  for (int i = 1; i <= N; i++) {
    s.append(std::to_string(i));
  }
  
  do {
    if (s.size() < 3) {
      std::cout << s << std::endl;
    } else if (is_zigzag(s)) {
      std::cout << s << std::endl;
    }
  } while (std::next_permutation(s.begin(), s.end()));
  return 0;
}
