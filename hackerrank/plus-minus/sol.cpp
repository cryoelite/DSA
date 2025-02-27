// Problem: https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>
class Alg
{
public:
    size_t n;
    std::vector<short int> arr;

    Alg()
    {
        std::cin >> n;
        arr = std::vector<short int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
    }

    std::array<float, 3> compute()
    {
        std::array<float, 3> result{0, 0, 0};
        for (size_t i{0}; i < n; ++i)
        {
            if (arr[i] > 0)
            {
                result[0]++;
            }
            else if (arr[i] < 0)
            {
                result[1]++;
            }
            else
            {
                result[2]++;
            }
        }
        result[0]/=n;
        result[1]/=n;
        result[2]/=n;
        return result;
    }

    void compute_and_output()
    {
        auto result = compute();
        std::cout.precision(6);
        std::cout << std::fixed;
        std::cout << result[0] << '\n'
                  << result[1] << '\n'
                  << result[2];
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
