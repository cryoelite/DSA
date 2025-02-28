// Problem: https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

#include <iostream>
#include <array>
class Alg
{
public:
    constexpr static int n{5};
    std::array<unsigned long long int, n> arr;

    Alg()
    {
        arr = std::array<unsigned long long int, n>{};

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
    }

    void compute()
    {
        unsigned long long int min_sum{0};
        unsigned long long int max_sum{0};
        unsigned long long int min_elem{arr[0]};
        unsigned long long int max_elem{arr[0]};
        unsigned long long int total_sum{0};

        for (size_t i{0}; i < n; ++i)
        {
            total_sum += arr[i];
            if (arr[i] < min_elem)
            {
                min_elem = arr[i];
            }
            else if (arr[i] > max_elem)
            {
                max_elem = arr[i];
            }
        }
        min_sum = total_sum - max_elem;
        max_sum = total_sum - min_elem;
        std::cout << min_sum << ' ' << max_sum;
    }

    void compute_and_output()
    {
        compute();
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
