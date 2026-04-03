#include "command.h"
#include "algorithms.h"
#include "utils.h"

using namespace std;

void execute_algorithm(string alg, string outputFile, vector<vector<char>> &dict, vector<string> &testCase)
{
    if (alg == "bf")
    {
        auto start = chrono::high_resolution_clock::now();
        int n = testCase.size();
        for (int i = 0; i < n; i++)
        {
            vector<MatchResult> res = BFSearch_2D(dict, testCase[i]);
            writeOuputRes(outputFile, res, testCase[i]);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        // Dem phep so sanh
        long long comp = 0;
        for (int i = 0; i < n; i++)
        {
            comp += BFSearch_2D_Comparisons(dict, testCase[i]);
        }
        writeAlgorithmCompTime(alg, comp, duration, outputFile);
    }
    else if (alg == "rk")
    {
    }
    else if (alg == "kmp")
    {
        // Dem thoi gian
        auto start = chrono::high_resolution_clock::now();
        int n = testCase.size();
        for (int i = 0; i < n; i++)
        {
            vector<MatchResult> res = KMPSearch_2D(dict, testCase[i]);
            writeOuputRes(outputFile, res, testCase[i]);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        // Dem phep so sanh
        long long comp = 0;
        for (int i = 0; i < n; i++)
        {
            comp += KMPSearch_2D_Comparisons(dict, testCase[i]);
        }
        writeAlgorithmCompTime(alg, comp, duration, outputFile);
    }
    else if (alg == "bm")
    {
        auto start = chrono::high_resolution_clock::now();
        int n = testCase.size();
        for (int i = 0; i < n; i++)
        {
            vector<MatchResult> res = BMSearch_2D(dict, testCase[i]);
            writeOuputRes(outputFile, res, testCase[i]);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        // Dem phep so sanh
        long long comp = 0;
        for (int i = 0; i < n; i++)
        {
            comp += BMSearch_2D_cmp(dict, testCase[i]);
        }
        writeAlgorithmCompTime(alg, comp, duration, outputFile);
    }
    else
    {
        cout << "Undefined algorithm name. Please try again!" << endl;
        return;
    }
}
