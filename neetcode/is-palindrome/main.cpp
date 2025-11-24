// Problem: https://neetcode.io/problems/is-palindrome

#include <iostream>
#include <vector>
class Alg {
public:
  std::string s{};

  Alg() { std::getline(std::cin >> std::ws, s); }
  Alg(std::string &&s) : s(std::move(s)) {}

  bool compute() {
    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {
      if (!isalnum(*l)) {
        ++l;
        continue;
      }
      if (!isalnum(*r)) {
        --r;
        continue;
      }
      if (char(tolower(*r)) != char(tolower(*r))) {
        return false;
      } else {
        ++l;
        --r;
      }
    }

    return true;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {

public:
  bool isPalindrome(std::string s) { return Alg(std::move(s)).compute(); }
};

/// If argv has a value "LOCAL", then it is for local testing mode, otherwise,
/// it is for the online judge.
signed main(signed argc, char *argv[]) {
  if (argc >= 2 && std::string{argv[1]} == "LOCAL") {
    std::string cwd_str(argv[0]);
    std::string base = cwd_str.substr(0, cwd_str.find_last_of("/"));
    std::string input_dir{base + "/input.txt"};
    std::string output_dir{base + "/output.txt"};

    freopen(input_dir.c_str(), "r", stdin);
    freopen(output_dir.c_str(), "w", stdout);

    Alg().compute_and_output();
  } else { // Running Online
    Alg().compute_and_output();
  }
  return 0;
}
