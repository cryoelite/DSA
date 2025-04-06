// Problem: https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned long int s{}, t{}, a{}, b{}, m{}, n{};
    std::vector<signed long int> apples{};
    std::vector<signed long int> oranges{};
    unsigned long int count_apples{}, count_oranges{};

    Alg()
    {
        std::cin >> s >> t;
        std::cin >> a >> b;
        std::cin >> m >> n;

        apples = std::vector<signed long int>(m, 0);
        oranges = std::vector<signed long int>(n, 0);

        for (size_t i{0}; i < m; i++)
        {
            std::cin >> apples[i];
        }
        for (size_t i{0}; i < n; i++)
        {
            std::cin >> oranges[i];
        }
    }

    void compute()
    {
        count_apples = 0;
        count_oranges = 0;
        for (size_t i{0}; i < m; i++)
        {
            count_apples += (a + apples[i] >= s && a + apples[i] <= t) ? 1 : 0;
        }
        for (size_t i{0}; i < n; i++)
        {
            count_oranges += (b + oranges[i] >= s && b + oranges[i] <= t) ? 1 : 0;
        }
    }

    void compute_and_output()
    {
        compute();
        std::cout << count_apples << '\n';
        std::cout << count_oranges << '\n';
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
