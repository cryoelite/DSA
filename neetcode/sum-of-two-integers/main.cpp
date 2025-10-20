// Problem: https://neetcode.io/problems/sum-of-two-integers?list=neetcode250

#include <bitset>
#include <iostream>
#include <vector>
class Alg {
public:
  int a;
  int b;

  Alg() { std::cin >> a >> b; }
  Alg(int a, int b) : a(a), b(b) {}

  int compute() {
    int result{a ^ b};
    int carry{(a & b) << 1};
    while (carry != 0) {
      int tmp{((result & carry) << 1)};
      result = result ^ carry;
      carry = tmp;
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
  int getSum(int a, int b) { return Alg(a, b).compute(); }
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
