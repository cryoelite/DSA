// Problem: https://neetcode.io/problems/reverse-string

#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<char> s{};

  Alg() {
    std::cin >> n;
    s = std::vector<char>(n, '0');

    for (size_t i = 0; i < n; i++) {
      std::cin >> s[i];
    }
  }
  Alg(size_t n, std::vector<char> &&s) : n(n), s(std::move(s)) {}

  void compute() {
    if (s.size() <= 1) {
      return;
    }
    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {
      std::iter_swap(l++, r--);
    }
    return;
  }

  void compute_and_output() {
    for (auto &elem : s) {
      std::cout << elem << " ";
    }
    std::cout << '\n';
    compute();

    for (auto &elem : s) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

class Solution {

public:
  void reverseString(std::vector<char> &s) {
    if (s.size() <= 1) {
      return;
    }

    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {
      std::iter_swap(l++, r--);
    }
    return;
  }
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
