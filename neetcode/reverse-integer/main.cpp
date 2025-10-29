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

    constexpr int k_int_max{std::numeric_limits<int>::max()};
    constexpr int k_int_min{std::numeric_limits<int>::min()};
    if (x == 0 || x == k_int_min) {
      return 0;
    }
    int result{0};
    bool is_x_pos{x >= 0};
    if (!is_x_pos) {
      x *= -1;
    }
    int n{static_cast<int>(std::floor(std::log10(x)))};

    while (x > 0) {
      int curr{static_cast<int>(x % 10)};
      int mult{static_cast<int>(std::pow(10, n))};

      if (mult != 0 && curr > (k_int_max / mult)) {
        return 0;
      } else {
        curr *= mult;
      }
      x = static_cast<int>(x / 10);
      if (curr!= 0 && result > k_int_max - curr) {
        return 0;
      }
      result += curr;
      --n;
    }

    if (!is_x_pos) {
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
