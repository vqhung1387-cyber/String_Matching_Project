#include "utils.h"

using namespace std;

void readInputFile(string filename, vector<vector<char>> &dict, vector<string> &testCase)
{
    ifstream fin(filename, ios::in);
    if (!fin.is_open())
    {
        cout << "Cannot open " << filename << endl;
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
}

void writeAlgorithmCompTime(string name, int cmp, int time, ofstream &fout)
{
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
        fout << "Cannot find this algorithm." << endl;
        return;
    }
}

void writeOuputFile(string filename, vector<string> &results, int argc, char *argv[])
{
    ofstream fout(filename, ios::out);
    if (!fout.is_open())
    {
        cout << "Cannot open " << filename << endl;
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        fout << "------";
    }
    fout << endl;
}
