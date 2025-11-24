// Problem: https://neetcode.io/problems/valid-palindrome-ii

#include <iostream>
#include <vector>
class Alg {
public:
  std::string s{};

  Alg() { std::getline(std::cin >> std::ws, s); }
  Alg(std::string s) : s(s) {}

  bool is_palindrome(std::string::iterator l, std::string::iterator r) {
    while (l < r) {
      if (*l != *r) {
        return false;
      }
      ++l;
      --r;
    }
    return true;
  }
  bool compute() {
    auto l{s.begin()};
    auto r{s.end() - 1};

    while (l < r) {
      if (*l != *r) {
        return is_palindrome(l + 1, r) || is_palindrome(l, r - 1);
      }

      ++l;
      --r;
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
  bool validPalindrome(std::string s) { return Alg(std::move(s)).compute(); }
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
