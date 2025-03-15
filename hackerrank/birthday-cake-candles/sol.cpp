// Problem: https://www.hackerrank.com/challenges/birthday-cake-candles

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned long int n;
    std::vector<unsigned long int> candles;

    Alg()
    {
        std::cin >> n;
        candles = std::vector<unsigned long int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> candles[i];
        }
    }

    unsigned long int compute()
    {
        unsigned long int tallest{0};
        unsigned long int c_tallest{0};
        for (size_t i{0}; i < n; ++i)
        {
            if (candles[i] > tallest)
            {
                tallest = candles[i];
                c_tallest = 1;
            }
            else if (candles[i] == tallest)
            {
                c_tallest++;
            }
        }
        return c_tallest;
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
