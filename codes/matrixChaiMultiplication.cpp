#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int> &p, int n)
{

    // dp[i][j] = minimum cost to multiply
    // matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length = number of matrices in chain
    for (int length = 2; length < n; length++)
    {

        for (int i = 1; i < n - length + 1; i++)
        {

            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {

                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{

    // Matrices:
    // A1 = 10 x 30
    // A2 = 30 x 5
    // A3 = 5 x 60

    vector<int> dimensions = {10, 30, 5, 60};

    int n = dimensions.size();

    int result = matrixChainMultiplication(dimensions, n);

    cout << "Minimum number of scalar multiplications = "
         << result << endl;

    return 0;
}