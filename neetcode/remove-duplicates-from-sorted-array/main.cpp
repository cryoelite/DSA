// Problem: https://neetcode.io/problems/remove-duplicates-from-sorted-array

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

  static int compute(size_t n, std::vector<int> &nums) {
    int k{static_cast<int>(n)};
    int l{0};
    int r{static_cast<int>(n - 1)};
    int c{0};
    int prev{nums[n - 1]};
    while (c < r) {
      if (nums[c] != prev) {
        int temp{nums[r]};
        prev = nums[c];
        nums[r] = nums[c];
        nums[c] = temp;
        --r;
      } else {
        int temp{nums[l]};
        nums[l] = nums[c];
        nums[c] = temp;
        ++l;
        --k;
      }
      ++c;
    }

    for (size_t i{0}; i < n / 2; ++i) {
      int temp{nums[n - i - 1]};
      nums[n - i - 1] = nums[i];
      nums[i] = temp;
    }

    return k;
  }

  void compute_and_output() {
    std::cout << compute(n, nums);
    std::cout << std::endl;
  }
};

class Solution {

public:
  int removeDuplicates(std::vector<int> &nums) {
    return Alg::compute(nums.size(), nums);
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
