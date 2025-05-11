// Problem: https://www.hackerrank.com/challenges/between-two-sets

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned short int n{}, m{};
    std::vector<unsigned short int> a;
    std::vector<unsigned short int> b;

    Alg()
    {
        std::cin >> n >> m;
        a = std::vector<unsigned short int>(n, 0);
        b = std::vector<unsigned short int>(m, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
        for (size_t j = 0; j < m; j++)
        {
            std::cin >> b[j];
        }
    }
    int gcd(int a, int b)
    {
        if (a % b == 0)
            return b;
        else
            return gcd(b, a % b);
    }

    int lcm(int a, int b)
    {
        return abs(a * b) / gcd(a, b);
    }

    std::vector<unsigned short int> compute()
    {
        auto result{std::vector<unsigned short int>()};

        unsigned short int lcm_a{a[0]}, gcd_b{b[0]};

        for (size_t i{}; i < n; ++i)
        {
            lcm_a = lcm(lcm_a, a[i]);
        }

        for (size_t j{}; j < m; ++j)
        {
            gcd_b = gcd(gcd_b, b[j]);
        }
        for (unsigned short int i{1}; i * lcm_a <= gcd_b; ++i)
        {
            if (gcd_b % (i * lcm_a) == 0)
            {
                result.push_back(i * lcm_a);
            }
        }

        return result;
    }

    void compute_and_output()
    {
        std::cout << compute().size();
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
