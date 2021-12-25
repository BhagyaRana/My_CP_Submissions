#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1]; //knapsack
    int ans[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) // Base Condition
            {
                K[i][w] = 0;
                ans[i][w] = 0;
            }
            else if (wt[i - 1] <= w) // Check if its Less than knapsack Size
            {

                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);

                ans[i][w] = max(val[i - 1] + ans[i - 1][w - wt[i - 1]], ans[i - 1][w]);
            }
            else if (wt[i - 1] / 2 <= w) // Check also for Weight/2 Size
            {
                ans[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1] / 2], ans[i - 1][w]);
            }
            else // No need to Include it in knapsack
            {
                K[i][w] = K[i - 1][w];
                ans[i][w] = ans[i - 1][w];
            }
        }
    }
    return ans[n][W];
}

int main()
{

    int n, m;
    cin >> n >> m;

    int wt[n], val[n];
    string s;
    char ch;
    int value, weight;
    int t = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> ch >> weight >> value;
        if (ch == 'S')
        {
            wt[t] = weight;
            val[t] = value;
            t++;
        }
    }
    // Bubble Sorting 
    int temp;
    for (int i = t - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (wt[j] < wt[i])
            {
                temp = wt[j];
                wt[j] = wt[i];
                wt[i] = temp;
                temp = val[j];
                val[j] = val[i];
                val[i] = temp;
            }
        }
    }

    int ans = knapsack(m, wt, val, t); //Little Modified KnapSack
    cout << ans << endl;

    return 0;
}