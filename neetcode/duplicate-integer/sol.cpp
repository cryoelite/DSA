// Problem: https://neetcode.io/problems/duplicate-integer

#include <vector>
#include <iostream>
class Alg {
public:
  size_t n;
  std::vector<int> nums;
  Alg(){
    n=0;
    std::cin >>n;
    nums=std::vector<int>(n,0);
    for(size_t i=0;i<n;i++){
      std::cin >> nums[i];
    } 
  }
  Alg(int n, std::vector<int> &nums) : n(n), nums(std::move(nums)) {}

  bool compute() {}

  void compute_and_output() {
    std::cout<<compute()<<std::endl;
  }
};

class Solution {

public:
  bool hasDuplicate(std::vector<int> &nums) {
    return Alg(nums.size(), nums).compute();
  }
};

/// If argv has a value "LOCAL", then it is for local testing mode, otherwise,
/// it is for the online judge.
#include <iostream>
#include <string>
signed main(signed argc, char *argv[]) {
  //std::cout << "Executing code" << std::endl;
  if (argc >= 2 && std::string{argv[1]} == "LOCAL") {
    //std::cout << "Running Locally" << std::endl;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Alg().compute_and_output();
  } else {
    //std::cout << "Running Online" << std::endl;
  }
  return 0;
}
