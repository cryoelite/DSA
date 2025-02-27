// Problem: https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
    size_t n;
    std::vector<std::vector<short int>> arr;

    Alg()
    {
        std::cin >> n;
        arr = std::vector<std::vector<short int>>(n, std::vector<short int>(n, 0));

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cin >> arr[i][j];
            }
        }
    }

    long long int compute()
    {
        long long int result{0};
        long long int sum_fd{0};
        long long int sum_bd{0};
        for (size_t i{0}; i < n; ++i)
        {
            sum_fd += arr[i][i];
            sum_bd += arr[i][n-i-1];
        }
        result = std::abs(sum_fd-sum_bd);
        return result;
    }

    void compute_and_output()
    {
        std::cout << compute();
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
