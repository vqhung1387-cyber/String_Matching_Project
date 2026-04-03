#include "command.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    string alg = "", inputFile = "", outputFile = "";

    // Phân tích tham số dòng lệnh thông minh
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "-a" && i + 1 < argc)
            alg = argv[++i];
        else if (arg == "-i" && i + 1 < argc)
            inputFile = argv[++i];
        else if (arg == "-o" && i + 1 < argc)
            outputFile = argv[++i];
    }

    // Kiểm tra xem người dùng có nhập đủ không
    if (alg.empty() || inputFile.empty() || outputFile.empty())
    {
        cout << "Usage: crossword.exe -a [algorithm] -i [input_file] -o [output_file]\n";
        return 1;
    }

    vector<vector<char>> dict;
    vector<string> testCase;

    readInputFile(inputFile, dict, testCase);
    execute_algorithm(alg, outputFile, dict, testCase);

    return 0;
}