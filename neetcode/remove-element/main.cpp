// Problem: https://neetcode.io/problems/remove-element

#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> arr{};
  int val{};

  Alg() {
    std::cin >> n >> val;
    arr = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
  }
  Alg(size_t n, std::vector<int> &&arr, int val)
      : n(n), arr(std::move(arr)), val(val) {}

  int compute() {
    int result{0};
    if (n==0) {
        return result;
    }
    auto l{arr.begin()};
    auto r{arr.end() - 1};

    while (l <= r) {
      if (*l == val) {
        std::iter_swap(l, r);
        --r;
      } else {
        ++l;
        ++result;
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
  int removeElement(std::vector<int> &nums, int val) {
    return Alg(nums.size(), std::move(nums), val).compute();
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
