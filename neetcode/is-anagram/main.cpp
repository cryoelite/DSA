// Problem: https://neetcode.io/problems/is-anagram

#include <algorithm>
#include <array>
#include <iostream>
class Alg {
public:
  std::string a{};
  std::string b{};

  Alg() {
    std::getline(std::cin >> std::ws, a);
    std::getline(std::cin >> std::ws, b);
  }
  Alg(std::string &&a, std::string &&b) : a(std::move(a)), b(std::move(b)) {}

  bool compute() {
    bool result{false};
    size_t n{a.size()};
    size_t m{b.size()};
    std::array<int, 26> t{};
    std::fill(t.begin(), t.end(), 0);

    for (size_t i{0}; i < std::max(n, m); ++i) {
      if (i < n) {
        ++t[a[i] % 26];
      }
      if (i < m) {
        --t[b[i] % 26];
      }
    }

    result = !std::any_of(t.begin(), t.end(), [](int i) { return i != 0; });
    return result;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {

public:
  bool isAnagram(std::string s, std::string t) {
    return Alg(std::move(s), std::move(t)).compute();
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
