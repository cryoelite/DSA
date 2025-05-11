// Problem: https://www.hackerrank.com/challenges/the-birthday-bar

#include <iostream>
#include <vector>
class Alg
{
public:
    unsigned short int n{}, d{}, m{};
    std::vector<unsigned short int> s{};

    Alg()
    {
        std::cin >> n;
        s = std::vector<unsigned short int>(n, 0);

        for (size_t i = 0; i < n; i++)
        {
            std::cin >> s[i];
        }

        std::cin >> d >> m;
    }

    unsigned short int compute()
    {
        unsigned short int result{0};
        unsigned short int seg_count{0};
        unsigned short int seg_sum{0};
        unsigned short int i{0};
        while (i <= n - m)
        {
            for (unsigned short int j{i}; j <= i + m; ++j)
            {
                ++seg_count;
                seg_sum += s[j];

                if (seg_count == m && seg_sum == d)
                {

                    ++result;
                    break;
                }
                else if (seg_sum > d)
                {

                    break;
                }
            }

            seg_count = 0;
            seg_sum = 0;
            ++i;
        }
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
