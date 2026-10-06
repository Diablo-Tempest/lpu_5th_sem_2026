#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int capacity, vector<int> &weight,
             vector<int> &value, int n)
{

    // DP table
    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    // Build the table
    for (int i = 1; i <= n; i++)
    {

        for (int w = 1; w <= capacity; w++)
        {

            // If current item can fit
            if (weight[i - 1] <= w)
            {

                dp[i][w] = max(
                    value[i - 1] +
                        dp[i - 1][w - weight[i - 1]],

                    dp[i - 1][w]);
            }

            // If item cannot fit
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};

    int capacity = 7;

    int n = weight.size();

    int result = knapsack(capacity, weight, value, n);

    cout << "Maximum value = " << result << endl;

    return 0;
}