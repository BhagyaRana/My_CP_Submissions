
// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Returns the minimum value of the difference of the two sets.
ll findMin(ll arr[], ll n)
{
    // Calculate sum of all elements
    ll sum = 0;
    for (ll i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (ll i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (ll i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    // Initialize difference of two sums.
    ll diff = 1e10;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (ll j = sum / 2; j >= 0; j--)
    {
        // Find the
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}
ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

// Driver program to test above function
int main()
{
    ll k;
    cin >> k;
    ll t;
    cin >> t;
    ll n, i;
    while (t--)
    {
        cin >> n;
        ll arr[n];
        for (i = 0; i < n; i++)
        {
            arr[i] = power(i + 1, k);
        }
        cout << n << " -> " << findMin(arr, n) << endl;
    }
    return 0;
}
