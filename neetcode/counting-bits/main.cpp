// Problem: https://neetcode.io/problems/counting-bits

#include <cmath>
#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> result;
  Alg() { std::cin >> n; }
  Alg(int in_n) {
    if (in_n < 0) {
      throw;
    }
    n = static_cast<size_t>(in_n);
  }

  void compute() {
    result = std::vector<int>(n + 1, 0);
    if (n > 0) {
      result[0] = 0;
      result[1] = 1;
    }
    for (size_t i{2}; i <= n; ++i) {
      result[i] = 1 + result[i - static_cast<size_t>(
                                     std::pow(2, std::floor(std::log2(i))))];
    }
  }

  void compute_and_output() {
    compute();
    for (int elem : result) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

class Solution {

public:
  std::vector<int> countBits(int n) {
    Alg alg{Alg(n)};
    alg.compute();
    return alg.result;
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
