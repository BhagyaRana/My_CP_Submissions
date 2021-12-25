#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

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

#define MAX 100000
#define bitmxn 31

// All Functions Here
int zerocnt[bitmxn][MAX];

ll cost[bitmxn][MAX];

ll pow2[31];

ll csum[31];

void precompute(int arr[], int n)
{
    for (int i = 0; i < bitmxn; i++)
    {
        zerocnt[i][0] = ((arr[0] >> i) & 1);

        ll unset = pow2[i] - (csum[i] & arr[0]);

        if (unset > 0)
            cost[i][0] = unset;
        else
            cost[i][0] = 0;

        for (int j = 1; j < n; j++)
        {
            zerocnt[i][j] = ((arr[j] >> i) & 1);

            unset = pow2[i] - (csum[i] & arr[j]);

            if (unset > 0)
                cost[i][j] = unset;
            else
                cost[i][j] = 0;

            cost[i][j] += cost[i][j - 1];
            zerocnt[i][j] += zerocnt[i][j - 1];
        }
    }
}

ll solve(int l, int r)
{
    ll ans;

    for (int i = 0; i < bitmxn; i++)
    {
        int range;
        ll curr_cost;

        if (l == 0)
        {
            range = zerocnt[i][r];
            curr_cost = cost[i][r];
        }
        else
        {
            range = zerocnt[i][r] - zerocnt[i][l - 1];
            curr_cost = cost[i][r] - cost[i][l - 1];
        }

        // No Need to Check Further (BITWISE AND > 0)
        if (range == r - l + 1)
        {
            return 0;
        }

        if (i == 0)
        {
            ans = curr_cost;
        }
        else if (ans > curr_cost)
        {
            ans = curr_cost;
        }
    }

    // Control Flow Returns Here Only If BITWISE AND == 0
    return ans;
}

// All Variables Here

int main()
{
    b_v_r();
    // Number of Array Elements
    int n;
    cin >> n;

    // Array of Positive Integers
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    pow2[0] = 1; // 2^0 = 1
    for (int i = 1; i < 31; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        //cout<<pow2[i]<<" ";
    }

    csum[0] = 1; // 2^0
    csum[1] = 3; // 2^0 + 2^1
    for (int i = 2; i < 30; i++)
    {
        csum[i] = pow2[i + 1] - 1;
        // 2^0 + 2^1 + 2^2 + ... 2^i = 2^(i+1) - 1
    }
    csum[30] = pow2[30] * 2 - 1;

    // Precomputation Function for Cost to Set the ith Bit
    precompute(a, n);

    int l, r;
    w(q)
    {
        cin >> l >> r;
        cout << solve(l - 1, r - 1) << endl;
    }

    return 0;
}