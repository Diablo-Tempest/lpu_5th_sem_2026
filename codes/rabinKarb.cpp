#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    const int d = 256; // Number of characters
    const int q = 101; // Prime number for modulo hashing

    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++)
    {

        // If hash values match
        if (patternHash == textHash)
        {

            // Check characters to avoid collision
            int j;

            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash for next window
        if (i < n - m)
        {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;

            // Make hash positive
            if (textHash < 0)
                textHash += q;
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    rabinKarp(text, pattern);

    return 0;
}