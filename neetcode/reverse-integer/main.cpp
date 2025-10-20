// Problem: https://neetcode.io/problems/reverse-integer

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

class Alg {
public:
  int x{};
  Alg() { std::cin >> x; }
  Alg(int x) : x(x) {}

  int compute() {
    int result{0};
    bool is_pos{x > 0};
    if (!is_pos) {
      x *= -1;
    }
    int n{static_cast<int>(std::floor(log10(x)))};
    while (x > 0) {
      int digit{x % 10};
      x = static_cast<int>(std::round(x / 10));
      int base{static_cast<int>(std::pow(10, n))};
      if (digit != 0 && digit > (std::numeric_limits<int>::max() /
                                 static_cast<int>(std::pow(10, n)))) {
        return 0;
      }
      int value{digit * base};
      if (value > 0 && result > std::numeric_limits<int>::max() - value) {
        return 0;
      }
      result += value;
      --n;
    }

    if (!is_pos) {
      result *= -1;
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
  int reverse(int x) { return Alg(x).compute(); }
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
