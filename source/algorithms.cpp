#include "algorithms.h"
#include "command.h"

using namespace std;

void computeLPSArray(string pattern, int M, vector<int> &lps)
{
    int length = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0
    int i = 1;

    // Loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        { // pattern[i] != pattern[length]
            if (length != 0)
            {
                // Do not increment i here
                length = lps[length - 1];
            }
            else
            { // length == 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search Function
void KMPSearch(string pattern, string text)
{
    int M = pattern.length();
    int N = text.length();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(M);

    // Preprocess the pattern to calculate lps[] array
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    bool found = false;

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout << "Pattern found at index " << i - j << "\n";
            found = true;
            j = lps[j - 1]; // Reset j to find the next match
        }
        // Mismatch after j matches
        else if (i < N && pattern[j] != text[i])
        {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found in the text.\n";
    }
}