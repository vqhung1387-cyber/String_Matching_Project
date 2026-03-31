#include "algorithms.h"
#include "command.h"

using namespace std;

void computeLPSArray(const string &pattern, int M, vector<int> &lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<MatchResult> KMPSearch_2D(const vector<vector<char>> &grid, const string &pattern)
{
    vector<MatchResult> results;
    int M = pattern.length();

    if (M == 0 || grid.empty() || grid[0].empty())
        return results;

    int Rows = grid.size();
    int Cols = grid[0].size();

    vector<int> lps(M);
    computeLPSArray(pattern, M, lps);

    for (int r = 0; r < Rows; r++)
    {
        int i = 0;
        int j = 0;
        while (i < Cols)
        {
            if (pattern[j] == grid[r][i])
            {
                j++;
                i++;
            }
            if (j == M)
            {
                results.push_back({r, i - j, r, i - 1});
                j = lps[j - 1];
            }
            else if (i < Cols && pattern[j] != grid[r][i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

    // 2. Tìm kiếm theo chiều dọc (Từng cột)
    for (int c = 0; c < Cols; c++)
    {
        int i = 0;
        int j = 0;
        while (i < Rows)
        {
            if (pattern[j] == grid[i][c])
            {
                j++;
                i++;
            }
            if (j == M)
            {
                results.push_back({i - j, c, i - 1, c});
                j = lps[j - 1];
            }
            else if (i < Rows && pattern[j] != grid[i][c])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

    return results;
}
long long computeLPSArray_Comp(const string &pattern, int M, vector<int> &lps)
{
    long long comps = 0;
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M)
    {
        comps++; // Đếm phép so sánh
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return comps;
}

// Hàm KMP trên mảng 2 chiều trả về TỔNG SỐ PHÉP SO SÁNH
long long KMPSearch_2D_Comparisons(const vector<vector<char>> &grid, const string &pattern)
{
    long long total_comparisons = 0;
    int M = pattern.length();

    if (M == 0 || grid.empty() || grid[0].empty())
        return 0;

    int Rows = grid.size();
    int Cols = grid[0].size();

    vector<int> lps(M);
    total_comparisons += computeLPSArray_Comp(pattern, M, lps);

    // 1. Tìm kiếm theo chiều ngang
    for (int r = 0; r < Rows; r++)
    {
        int i = 0;
        int j = 0;
        while (i < Cols)
        {
            total_comparisons++; // Đếm so sánh ký tự
            if (pattern[j] == grid[r][i])
            {
                j++;
                i++;
            }
            if (j == M)
            {
                j = lps[j - 1];
            }
            else if (i < Cols && pattern[j] != grid[r][i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

    // 2. Tìm kiếm theo chiều dọc
    for (int c = 0; c < Cols; c++)
    {
        int i = 0;
        int j = 0;
        while (i < Rows)
        {
            total_comparisons++; // Đếm so sánh ký tự
            if (pattern[j] == grid[i][c])
            {
                j++;
                i++;
            }
            if (j == M)
            {
                j = lps[j - 1];
            }
            else if (i < Rows && pattern[j] != grid[i][c])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

    return total_comparisons;
}