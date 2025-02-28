// Problem: https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
    size_t n;

    Alg()
    {
        std::cin >> n;
    }

    void compute()
    {
        for (size_t i{1}; i <= n; ++i)
        {
            for(size_t j{1}; j<= (n-i); ++j) {
                std::cout<<' ';
            }
            for(size_t j{1}; j<= i; ++j) {
                std::cout<<'#';
            }
            std::cout<<'\n';
        }
    }

    void compute_and_output()
    {
        compute();
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
