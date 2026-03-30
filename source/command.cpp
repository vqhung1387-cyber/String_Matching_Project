#include "command.h"
#include "algorithms.h"

using namespace std;

void execute_algorithm(string alg, vector<vector<char>> &dict, vector<string> &testCase)
{
    int time, comp;
    vector<pair<int, int>> res;
    if (alg == "bf")
    {
    }
    else if (alg == "rk")
    {
    }
    else if (alg == "kmp")
    {
    }
    else if (alg == "bm")
    {
    }
    else
    {
        cout << "Undefined algorithm name. Please try again!" << endl;
        return;
    }
}

int main(int argc, char *argv[])
{
    vector<vector<char>> dict;
    vector<string> testCase;
    // readInputFile(string(argv[4]), dict, testCase);
    // execute_algorithm(string(argv[2]), dict, testCase);

    return 0;
}