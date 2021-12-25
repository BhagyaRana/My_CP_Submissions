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
typedef unsigned long long int ull;

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

// All Functions Here

// All Variables Here

const int LCM = 2520;
const int MAXDIG = 20;

// [1..9]
ll memo[MAXDIG][2][LCM][(1 << 9) + 5];
vector<int> dig;
int K;

ll dp(int index, int tight, int rem, int mask)
{
    ll &res = memo[index][tight][rem][mask];
    if (res != -1)
    {
        return res;
    }
    res = 0;
    if (index == dig.size())
    {
        int cnt = 0;
        for (int d = 1; d < 10; d++)
        {
            if (mask & (1 << (d - 1)))
            {
                if (rem % d == 0)
                {
                    cnt++;
                }
            }
        }
        if (cnt >= K)
        {
            res = 1;
        }
    }
    else
    {
        for (int d = 0; d < 10; d++)
        {
            if (tight & (d > dig[index]))
            {
                continue;
            }
            int newTight = ((tight == 1) ? (d == dig[index]) : 0);
            int newRem = (rem * 10 + d) % LCM;
            int newMask = mask;
            if (d != 0)
            {
                newMask = (mask | (1 << (d - 1)));
            }
            res += dp(index + 1, newTight, newRem, newMask);
        }
    }
    return res;
}

ll solve(ll n)
{
    dig.clear();
    if (n == 0)
    {
        dig.push_back(n);
    }
    while (n)
    {
        dig.push_back(n % 10);
        n /= 10;
    }
    reverse(dig.begin(), dig.end());
    memset(memo, -1, sizeof(memo));
    return dp(0, 1, 0, 0);
}

int main()
{
    b_v_r();

    w(t)
    {
        ll l, r;
        cin >> l >> r >> K;
        ll ans = solve(r) - solve(l - 1);
        cout << ans << endl;
    }

    return 0;
}