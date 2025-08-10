// Problem: https://neetcode.io/problems/single-number

#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> nums{};

  Alg() {
    std::cin >> n;
    nums = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> nums[i];
    }
  }
  Alg(int n, std::vector<int> &arr) : n(n), nums(std::move(arr)) {}

  // Returns: The number in nums that doesn't appear twice
  int compute() {
    int result{0};
    for (size_t i{0}; i < n; ++i) {
      result ^= nums[i];
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
  int singleNumber(std::vector<int> &nums) {
    return Alg(nums.size(), nums).compute();
  }
};

/// If argv has a value "LOCAL", then it is for local testing mode, otherwise,
/// it is for the online judge.
signed main(signed argc, char *argv[]) {
  // std::cout << "Executing code" << std::endl;
  if (argc >= 2 && std::string{argv[1]} == "LOCAL") {
    // std::cout << "Running Locally" << std::endl;
    std::string cwd_str(argv[0]);
    std::string base = cwd_str.substr(0, cwd_str.find_last_of("/"));
    std::string input_dir{base + "/input.txt"};
    std::string output_dir{base + "/output.txt"};

    freopen(input_dir.c_str(), "r", stdin);
    freopen(output_dir.c_str(), "w", stdout);

    Alg().compute_and_output();
  } else {
    // std::cout << "Running Online" << std::endl;
    Alg().compute_and_output();
  }
  return 0;
}
