// Problem: https://neetcode.io/problems/two-integer-sum

#include <iostream>
#include <unordered_map>
#include <vector>
class Alg {
public:
  size_t n{};
  int target{};
  std::vector<int> arr{};

  Alg() {
    std::cin >> n >> target;
    arr = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
  }
  Alg(int target, size_t n, std::vector<int> &&arr)
      : n(n), target(target), arr(std::move(arr)) {}

  std::vector<int> compute() {
    std::vector<int> result{std::vector<int>(2, 0)};
    std::unordered_map<int, int> t{std::unordered_map<int, int>()};
    for (size_t i{0}; i < n; ++i) {
      std::unordered_map<int, int>::iterator it{t.find(target - arr[i])};

      if (it != t.end()) {
        result[0] = static_cast<int>(it->second);
        result[1] = static_cast<int>(i);
        break;
      }
      t.insert({arr[i], i});
    }
    return result;
  }

  void compute_and_output() {
    std::vector<int> res{compute()};
    for (int elem : res) {
      std::cout << elem << " ";
    }

    std::cout << std::endl;
  }
};

class Solution {

public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    return Alg(target, nums.size(), std::move(nums)).compute();
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
