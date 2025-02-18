// Problem: https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
  std::vector<short int> a;
  std::vector<short int> b;

  Alg()
  {
    a = std::vector<short int>(3, 0);
    b = std::vector<short int>(3, 0);

    for (size_t i = 0; i < 3; i++)
    {
      std::cin >> a[i];
    }
    for (size_t i = 0; i < 3; i++)
    {
      std::cin >> b[i];
    }
  }

  std::vector<short int> compute()
  {
    std::vector<short int> c{std::vector<short int>(2, 0)};
    for (size_t i{0}; i < 3; i++)
    {
      if (a[i] > b[i])
      {
        c[0]++;
      }
      else if (a[i] < b[i])
      {
        c[1]++;
      }
    }
    return c;
  }

  void compute_and_output()
  {
    for (short int elem : compute())
    {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

/// If argv has a value "LOCAL", then it is for local testing mode, otherwise,
/// it is for the online judge.
signed main(signed argc, char *argv[])
{
  // std::cout << "Executing code" << std::endl;
  if (argc >= 2 && std::string{argv[1]} == "LOCAL")
  {
    // std::cout << "Running Locally" << std::endl;
    std::string cwd_str(argv[0]);
    std::string base = cwd_str.substr(0, cwd_str.find_last_of("/"));
    std::string input_dir{base + "/input.txt"};
    std::string output_dir{base + "/output.txt"};

    freopen(input_dir.c_str(), "r", stdin);
    freopen(output_dir.c_str(), "w", stdout);

    Alg().compute_and_output();
  }
  else
  {
    // std::cout << "Running Online" << std::endl;
    Alg().compute_and_output();
  }
  return 0;
}
