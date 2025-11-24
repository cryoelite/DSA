// Problem: https://neetcode.io/problems/merge-sorted-array

#include <iostream>
#include <vector>
class Alg {
public:
  int n{};
  int m{};
  size_t nums1_size{};
  size_t nums2_size{};
  std::vector<int> nums1{};
  std::vector<int> nums2{};

  Alg() {
    std::cin >> nums1_size >> nums2_size >> m >> n;
    nums1 = std::vector<int>(nums1_size, 0);
    nums2 = std::vector<int>(nums2_size, 0);

    for (size_t i = 0; i < nums1_size; i++) {
      std::cin >> nums1[i];
    }
    for (size_t i = 0; i < nums2_size; i++) {
      std::cin >> nums2[i];
    }
  }

  static void compute(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int l{m - 1};
    int r{n - 1};
    int z{m + n - 1};
    while (l >= 0 && r >= 0) {
      if (nums1[static_cast<size_t>(l)] > nums2[static_cast<size_t>(r)]) {
        nums1[static_cast<size_t>(z)] = nums1[static_cast<size_t>(l)];
        --l;

      } else {
        nums1[static_cast<size_t>(z)] = nums2[static_cast<size_t>(r)];
        --r;
      }
      --z;
    }

    while (r>=0) {
      nums1[static_cast<size_t>(z)]=nums2[static_cast<size_t>(r)];
      --r;
      --z;
    }
  }

  void compute_and_output() {
    compute(nums1, m, nums2, n);
    for (int elem : nums1) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

class Solution {

public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    Alg().compute(nums1, m, nums2, n);
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
