#include "utils.h"
#include "algorithms.h"

using namespace std;

int cnt = 0;

void readInputFile(string filename, vector<vector<char>> &dict, vector<string> &testCase)
{
    ifstream fin(filename, ios::in);

    if (!fin.is_open())
    {
        cout << "Cannot open " << filename << " to get input." << endl;
        return;
    }
    int r, c;
    fin >> r >> c;
    dict.assign(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fin >> dict[i][j];
        }
    }
    int k;
    fin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        fin >> s;
        testCase.push_back(s);
    }
    fin.close();
}

void writeAlgorithmCompTime(string name, long long cmp, chrono::duration<double> time, string filename)
{
    ofstream fout;
    if (cnt == 0)
    {
        fout.open(filename, ios::out);
        cnt += 1;
    }
    else
        fout.open(filename, ios::out | ios::app);

    if (!fout.is_open())
    {
        cout << "Cannot open " << filename << " to write output." << endl;
    }
    for (int i = 0; i < 7; i++)
    {
        fout << "------";
    }
    fout << endl;
    fout << "Algorithm: ";
    if (name == "bf")
        fout << "BF" << endl;
    else if (name == "rk")
        fout << "RK" << endl;
    else if (name == "kmp")
        fout << "KMP" << endl;
    else if (name == "bm")
        fout << "BM" << endl;
    else
    {
        cout << "Cannot find this algorithm." << endl;
        return;
    }
    fout << "Comparisons: " << cmp << endl;
    fout << "Execution Time: " << time.count() * 1000 << " ms";
    fout.close();
}

void writeOuputRes(string filename, vector<MatchResult> &results, string testName)
{
    ofstream fout;
    if (cnt == 0)
    {
        fout.open(filename, ios::out);
        cnt += 1;
    }
    else
        fout.open(filename, ios::out | ios::app);

    if (!fout.is_open())
    {
        cout << "Cannot open " << filename << " to write output." << endl;
        return;
    }

    fout << testName << ": ";
    int n = results.size();
    if (n == 0)
    {
        fout << "not found" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        fout << "(" << results[i].start_row << ", " << results[i].start_col << ")" << " -> " << "(" << results[i].end_row << ", " << results[i].end_col << "); ";
    }
    fout << endl;
    fout.close();
}
