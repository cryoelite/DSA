// Problem: https://neetcode.io/problems/counting-bits

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
    for (size_t i{0}; i <= n; ++i) {
      int k{static_cast<int>(i)};
      while (k) {
        ++result[i];
        k &= (k - 1);
      }
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
