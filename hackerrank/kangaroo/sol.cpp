// Problem: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#include <iostream>
#include <string>
#include <cmath>
class Alg
{
public:
    unsigned short int x1{}, v1{}, x2{}, v2{};

    Alg()
    {
        std::cin >> x1 >> v1 >> x2 >> v2;
    }

    std::string compute()
    {
        if (v2 - v1 == 0 || x1 - x2 == 0)
        {
            return "NO";
        }
        double y{static_cast<double>((x1 - x2)) / (v2 - v1)};
        if (y > 0 && y == std::floor(y)) {
            return "YES";
        }
        return "NO";
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
