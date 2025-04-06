// Problem: https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned short int n;
    std::vector<unsigned short int> arr;

    Alg()
    {
        std::cin >> n;
        arr = std::vector<unsigned short int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
    }

    std::vector<unsigned short int> compute()
    {
        std::vector<unsigned short int> result{std::vector<unsigned short int>(n, 0)};
        for (size_t i{0}; i < n; i++)
        {
            if (arr[i] >= 38)
            {
                unsigned short int next_mult{(5 - (arr[i] % 5)) + arr[i]};
                if (next_mult - arr[i] < 3)
                {
                    result[i] = next_mult;
                }
                else
                {
                    result[i] = arr[i];
                }
            }
            else
            {
                result[i] = arr[i];
            }
        }
        return result;
    }

    void compute_and_output()
    {
        auto result{compute()};
        for (auto &elem : result)
        {
            std::cout << elem << '\n';
        }
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
