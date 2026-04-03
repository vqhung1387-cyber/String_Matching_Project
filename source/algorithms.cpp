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

// ----------------------------------------------------------------

void searchBM(const vector<char>& text, const string& pattern, bool horizontal, int fixedIdx, vector<MatchResult>& ans) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n) return;

    int badChar[26];
    for (int i = 0; i < 26; i++) {
        badChar[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        badChar[(pattern[i] - 'a')] = m - 1 - i;
    }

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            if (horizontal) {
                ans.push_back({ fixedIdx,s,fixedIdx,s + m - 1 });
            }
            else {
                ans.push_back({ s,fixedIdx,s + m - 1,fixedIdx });
            }
            s += badChar[(text[s + m - 1] - 'a')];
        }
        else {
            s += badChar[(text[s + m - 1] - 'a')];
        }
    }
}

vector<MatchResult> BMSearch_2D(const vector<vector<char>>& grid, const string& pattern) {
    int row = grid.size(), col = grid[0].size();
    vector<MatchResult> ans;

    for (int i = 0; i < row; i++) {
        searchBM(grid[i], pattern, true, i, ans);
    }


    for (int j = 0; j < col; j++) {
        vector<char> colData(row);
        for (int i = 0; i < row; i++) {
            colData[i] = grid[i][j];
        }
        searchBM(colData, pattern, false, j, ans);
    }
    return ans;
}

long long searchBM_cmp(const vector<char>& text, const string& pattern, bool horizontal, int fixedIdx) {
    long long total_comparison = 0;
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n) return 2;
    total_comparison += 2;

    int badChar[26];
    for (int i = 0; i < 26; i++, ++total_comparison) {
        badChar[i] = m;
    }

    for (int i = 0; i < m - 1; i++, ++total_comparison) {
        badChar[(pattern[i] - 'a')] = m - 1 - i;
    }

    int s = 0;
    while (s <= (n - m) && ++total_comparison) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j] && ++(++total_comparison)) {
            j--;
        }

        if (j < 0) {
            total_comparison++;
            if (horizontal) {
                total_comparison++;
            }
            else {
                total_comparison++;
            }
            s += badChar[(text[s + m - 1] - 'a')];
        }
        else {
            s += badChar[(text[s + m - 1] - 'a')];
        }
    }
    return total_comparison;
}

long long BMSearch_2D_cmp(const vector<vector<char>>& grid, const string& pattern) {
    long long total_comparison = 0;
    int row = grid.size(), col = grid[0].size();

    for (int i = 0; i < row; i++, ++total_comparison) {
        total_comparison += searchBM_cmp(grid[i], pattern, true, i);
    }


    for (int j = 0; j < col; j++, ++total_comparison) {
        vector<char> colData(row);
        for (int i = 0; i < row; i++, ++total_comparison) {
            colData[i] = grid[i][j];
        }
        total_comparison += searchBM_cmp(colData, pattern, false, j);
    }
    return total_comparison;
}

// --------------------------------------------------

//Kiem tra vi tri dang xet co nam trong matrix khong
bool isValid(int x, int y, int Rows, int Cols) {
	return x >= 0 && x < Rows && y >= 0 && y < Cols;
}


vector<MatchResult> BFSearch_2D(const vector<vector<char>>& grid, const string& pattern)
{

	int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

	vector<MatchResult> results;
	int lenPattern = pattern.size();

	if (lenPattern == 0 || grid.empty() || grid[0].empty())
		return results;

	int Rows = grid.size();
	int Cols = grid[0].size();

	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			if (grid[i][j] != pattern[0]) continue; //Tim ky tu dau

			for (int d = 0; d < 8; ++d) //Thu 8 huong
			{
				int x = i, y = j; // Xuat phat tu ky tu dau duoc tim thay
				int k;
				for (k = 1; k < lenPattern; ++k)
				{
					x = x + dx[d];
					y = y + dy[d];

					if (!isValid(x, y, Rows, Cols)) break;
					if (grid[x][y] != pattern[k]) break;
				}
				if (k == lenPattern) results.push_back({ i, j, x, y });
			}

		}
	}
	return results;
}

long long BFSearch_2D_Comparisons(const vector<vector<char>>& grid, const string& pattern)
{
	long long total_comparisons = 0;	
	int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

	vector<MatchResult> results;
	int lenPattern = pattern.size();

	if (lenPattern == 0 || grid.empty() || grid[0].empty())
		return 0;

	int Rows = grid.size();
	int Cols = grid[0].size();

	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			++total_comparisons;
			if (grid[i][j] != pattern[0]) continue; //Tim ky tu dau

			for (int d = 0; d < 8; ++d) //Thu 8 huong
			{
				int x = i, y = j; // Xuat phat tu ky tu dau duoc tim thay
				int k;
				for (k = 1; k < lenPattern; ++k)
				{
					x = x + dx[d];
					y = y + dy[d];

					if (!isValid(x, y, Rows, Cols)) break;

					++total_comparisons;
					if (grid[x][y] != pattern[k]) break;
				}
				if (k == lenPattern) results.push_back({ i, j, x, y });
			}

		}
	}
	return total_comparisons;
}