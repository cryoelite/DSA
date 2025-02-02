//Problem: https://neetcode.io/problems/duplicate-integer

/// If argv has a value "LOCAL", then it is for local testing mode, otherwise,
/// it is for the online judge.
#include <iostream>
#include <string>
signed main(signed argc, char *argv[]) {
  std::cout << "Executing code" << std::endl;
  if (argc >= 2 && std::string{argv[1]} == "LOCAL") {
    std::cout << "Running Locally" << std::endl;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

  } else {
    std::cout << "Running Online" << std::endl;
  }
  return 0;
}
