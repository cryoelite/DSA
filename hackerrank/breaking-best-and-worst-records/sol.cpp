// Problem: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned short int n;
    std::vector<unsigned long int> scores;

    Alg()
    {
        std::cin >> n;
        scores = std::vector<unsigned long int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> scores[i];
        }
    }

    std::vector<unsigned short int> compute()
    {
        auto result{std::vector<unsigned short int>(2, 0)};
        unsigned long int max_elem{scores[0]};
        unsigned long int min_elem{scores[0]};
        for (int i{0}; i < n; ++i)
        {
            if (scores[i] > max_elem)
            {
                max_elem = scores[i];
                ++result[0];
            }
            else if(scores[i] < min_elem)
            {
                min_elem = scores[i];
                ++result[1];
            }
        }
        return result;
    }

    void compute_and_output()
    {
        auto result{compute()};
        std::cout << result[0] << " " << result[1];
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
