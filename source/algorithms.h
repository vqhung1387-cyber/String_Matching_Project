#pragma once
#include <string>
#include <vector>

using namespace std;
struct MatchResult
{
    int start_row, start_col;
    int end_row, end_col;
};

bool isValid(int, int, int, int);
vector<MatchResult> BFSearch_2D(const vector<vector<char>> &, const string &);
long long BFSearch_2D_Comparisons(const vector<vector<char>> &, const string &);
//--------------------------------------------------

void rabinKarp(const vector<char> &text, const string &pattern, vector<int> &matchIndices);
long long rabinKarpCountComparisons(const vector<char> &text, const string &pattern, vector<int> &matchIndices);

vector<MatchResult> rabinKarp2D(const vector<vector<char>> &grid, const string &pattern);
long long rabinKarp2Dcmp(const vector<vector<char>> &grid, const string &pattern, vector<MatchResult> &results);

//---------------------------------------------------

void computeLPSArray(const string &pattern, int M, vector<int> &lps);
vector<MatchResult> KMPSearch_2D(const vector<vector<char>> &grid, const string &pattern);

long long computeLPSArray_Comp(const string &pattern, int M, vector<int> &lps);
long long KMPSearch_2D_Comparisons(const vector<vector<char>> &grid, const string &pattern);

// --------------------------------------------------

void searchBM(const vector<char> &text, const string &pattern, bool horizontal, int fixedIdx, vector<MatchResult> &ans);
vector<MatchResult> BMSearch_2D(const vector<vector<char>> &grid, const string &pattern);

long long searchBM_cmp(const vector<char> &text, const string &pattern, bool horizontal, int fixedIdx);
long long BMSearch_2D_cmp(const vector<vector<char>> &grid, const string &pattern);

// ---------------------------------------------------

// --------------------------------------------------
// Z-ALGORITHM (BONUS)
void getZarr(const string &str, vector<int> &Z);
long long getZarr_cmp(const string &str, vector<int> &Z);
vector<MatchResult> ZSearch_2D(const vector<vector<char>> &grid, const string &pattern);
long long ZSearch_2D_cmp(const vector<vector<char>> &grid, const string &pattern);