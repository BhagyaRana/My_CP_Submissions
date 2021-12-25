// CPP program to print equal sum sets of array.
#include <bits/stdc++.h>
using namespace std;

// Function to print equal sum
// sets of array.
void printEqualSumSets(int arr[], int n)
{
    int i, currSum;

    // Finding sum of array elements
    int sum = accumulate(arr, arr + n, 0);

    // Check sum is even or odd. If odd
    // then array cannot be partitioned.
    // Print -1 and return.
    if (sum & 1)
    {
        cout << "-1";
        return;
    }

    // Divide sum by 2 to find
    // sum of two possible subsets.
    int k = sum >> 1;

    // Boolean DP table to store result
    // of states.
    // dp[i][j] = true if there is a
    // subset of elements in first i elements
    // of array that has sum equal to j.
    bool dp[n + 1][k + 1];

    // If number of elements are zero, then
    // no sum can be obtained.
    for (i = 1; i <= k; i++)
        dp[0][i] = false;

    // Sum 0 can be obtained by not selecting
    // any element.
    for (i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table in bottom up manner.
    for (i = 1; i <= n; i++)
    {
        for (currSum = 1; currSum <= k; currSum++)
        {

            // Excluding current element.
            dp[i][currSum] = dp[i - 1][currSum];

            // Including current element
            if (arr[i - 1] <= currSum)
                dp[i][currSum] = dp[i][currSum] |
                                 dp[i - 1][currSum - arr[i - 1]];
        }
    }

    // Required sets set1 and set2.
    vector<int> set1, set2;

    // If partition is not possible print
    // -1 and return.
    if (!dp[n][k])
    {
        cout << "-1\n";
        return;
    }

    // Start from last element in dp table.
    i = n;
    currSum = k;

    while (i > 0 && currSum >= 0)
    {

        // If current element does not
        // contribute to k, then it belongs
        // to set 2.
        if (dp[i - 1][currSum])
        {
            i--;
            set2.push_back(arr[i]);
        }

        // If current element contribute
        // to k then it belongs to set 1.
        else if (dp[i - 1][currSum - arr[i - 1]])
        {
            i--;
            currSum -= arr[i];
            set1.push_back(arr[i]);
        }
    }

    // Print elements of both the sets.
    cout << "Set 1 elements: ";
    for (i = 0; i < set1.size(); i++)
        cout << set1[i] << " ";
    cout << "\nSet 2 elements: ";
    for (i = 0; i < set2.size(); i++)
        cout << set2[i] << " ";
}

// Driver program.
int main()
{
    int arr[] = {1,4,9,16,25,36,49,64,81,100,121};
    int n = sizeof(arr) / sizeof(arr[0]);
    printEqualSumSets(arr, n);
    return 0;
}