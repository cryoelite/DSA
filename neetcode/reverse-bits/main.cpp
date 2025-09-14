// Problem: https://neetcode.io/problems/reverse-bits

#include <iostream>
#include <vector>
class Alg {
public:
  uint32_t n{};

  Alg() { std::cin >> n; }
  Alg(uint32_t &n) : n(n) {}

  uint32_t compute() {
    uint32_t result{0};

    for (size_t i{0}; i < 32; ++i) {
      if (n & (1 << i)) {
        result |= (1 << (31 - i));
      }
    }
    return result;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {

public:
  uint32_t reverseBits(uint32_t n) { return Alg(n).compute(); }
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
