#include <iostream>
using namespace std;

void naiveSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {

        int j = 0;

        // Compare pattern with current window
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }

        // Pattern completely matched
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    naiveSearch(text, pattern);

    return 0;
}