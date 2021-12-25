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

int dp[1002][1002];
int vis[1002];

int gcnt = 0;

int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    if (wt[n - 1] <= w)
    {
        int value1 = val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1);
        int value2 = knapsack(wt, val, w, n - 1);
        if (value1 > value2)
        {
            // cout << "N-1 : " << wt[n-1] << endl;
            gcnt += wt[n - 1];
            dp[n][w] = value1;
        }
        else
        {
            dp[n][w] = value2;
        }

        // dp[n][w] = max( val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));

        return dp[n][w];
    }
    else
    {
        if (wt[n - 1] > w)
        {
            {
                dp[n][w] = knapsack(wt, val, w, n - 1);
                return dp[n][w];
            }
        }
    }
}

bool cmp(const pair<ll, ll> &i, const pair<ll, ll> &j)
{
    double r1 = (double)i.second / i.first;
    double r2 = (double)j.second / j.first;
    return r1 > r2;
}

int main()
{
    b_v_r();
    int n, m;
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    cin >> n >> m; //Chocolates & Limit
    string chocname[n];
    char type[n];
    int sweet[n];
    int price[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> chocname[i];
        cin >> type[i];
        cin >> sweet[i];
        cin >> price[i];
        if (type[i] == 'S')
        {
            v.push_back(make_pair(sweet[i], price[i]));
        }
    }

    int new_n = v.size();
    // Aim : Maximise Price
    // O-1 KnapSack + Fractional KnapSack Combo
    // sort(v.begin(), v.end(), cmp);

    // reverse(v.begin(),v.end());

    // for (int i = 0; i < new_n; i++)
    // {
    //     cout << v[i].first << "  " << v[i].second << " : "
    //          << ((double)v[i].second / v[i].first) << endl;
    // }

    int wt[new_n];
    int val[new_n];

    for (int i = 0; i < new_n; i++)
    {
        wt[i] = v[i].first;
        val[i] = v[i].second;
    }

    int ans = knapsack(wt, val, m, new_n);
    int tempmax = 0;
    for (int i = 0; i < new_n; i++)
    {
        if (wt[i] >= m)
        {
            if ((wt[i] / 2) <= (m - gcnt))
            {
                if (val[i]>tempmax)
                    tempmax = val[i];
            }
        }
    }
    // for(int i=0;i<new_n;i++)
    // {
    //     if(vis[i]!=1)
    //     {

    //     }
    // }

    cout << ans + tempmax << endl;

    return 0;
}
