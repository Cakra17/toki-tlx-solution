#include <string>
#include <iostream>
#include <unordered_map>

typedef std::unordered_map<char, char> Map;

int N;
int MSGLENGTH = 3;

void inspectRules(
  std::string originalMsg, 
  std::string firstEncypted,
  Map& ori2enc, Map& enc2ori
) {
  
  for (int i = 0; i < N; i++) {
    char original = originalMsg[i];
    char encrypted = firstEncypted[i];

    if (ori2enc.count(original) && ori2enc[original] != encrypted) {
      throw "Pak Dengklek bingung";
    }

    if (enc2ori.count(encrypted) && enc2ori[encrypted] != original) {
      throw "Pak Dengklek bingung";
    }

    ori2enc[original] = encrypted;
    enc2ori[encrypted] = original;
  } 
}

std::string convertMsg(Map rules, std::string secondMsg) {
  std::string res; res.reserve(secondMsg.length());
  for (char c: secondMsg) {
    auto it = rules.find(c);
    if (it != rules.end()) {
      res += it->second;
    } else {
      res += "?";
    }
  }
  return res;
}

int main() {
  try {
    std::cin >> N;
    std::string msg[MSGLENGTH];

    for (int i = 0; i < MSGLENGTH; i++) {
      std::cin >> msg[i];
    }
    
    Map ori2enc, enc2ori;
    inspectRules(msg[0], msg[1], ori2enc, enc2ori);
    std::string result =  convertMsg(enc2ori, msg[2]);
    std::cout << result << std::endl;

  } catch (const char* message) {
    std::cout << message << std::endl; 
  }

  return 0;
}
