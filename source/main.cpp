#include "command.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<vector<char>> dict;
    vector<string> testCase;
    readInputFile(string(argv[4]), dict, testCase);
    execute_algorithm(string(argv[2]), string(argv[6]), dict, testCase);
    return 0;
}