// Problem: https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

#include <iostream>
#include <string>
class Alg
{
public:
    std::string inp{};

    Alg()
    {
        std::getline(std::cin, inp, '\n');
    }

    std::string compute()
    {
        std::string result{};

        result.assign(inp.begin(), inp.end() - 2);

        if (inp.ends_with("AM"))
        {
            if (result.starts_with("12"))
            {
                result[0] = '0';
                result[1] = '0';
            } // else leave as is
        }
        else
        { // ends with PM
            if (!result.starts_with("12"))
            {
                int hour{std::stoi(result.substr(0, 2))};
                hour += 12;
                std::string s_hour{std::to_string(hour)};
                std::copy(s_hour.begin(), s_hour.end(), result.begin());
            }
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
