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

const int sz = 20002;

short int dp[sz][sz];

int solve(int n, int k)
{
    if (dp[n][k] != -1)
        return dp[n][k];

    if (k == 0)
        return dp[n][k] = 1;
    if (n == 0)
        return dp[n][k] = 0;

    int j = 0, val = 0;
    for (j = 0; j < n && k - j >= 0; j++)
        val = (val + solve(n - 1, k - j)) % 2;

    return dp[n][k] = val % 2;
}

// All Variables Here
#define REP(i, n) for (int i(0); i < (int)(n); i++)
#define FOR(i, a, b) for (int i(a); i <= (int)(b); i++)

const int N = 2002, M = N*N/2;
int MOD = (int)2;
ll T, n;

bool a[N][M]={false}, s[M]={false};

int main()
{
    b_v_r();

    a[1][0] = 1;
    
    for (int n = 2; n <= N-2; n++)
    {
        int cnt = (n - 1) * (n - 2) / 2 + 1;

        s[0] = a[n - 1][0];
        // REP(i, cnt) printf("%d%c", s[i], i == cnt - 1 ? '\n' : ' ');
        int tnt = n * (n - 1) / 2 + 1;

        for (int i = 1; i < tnt; i++)
            s[i] = (s[i - 1] + a[n - 1][i]) % MOD;

        for (int i = 0; i < tnt; i++)
        {
            a[n][i] = s[i];
            if (i - n >= 0)
                a[n][i] = (a[n][i] + MOD - s[i - n]) % MOD;
        }
        // REP(i, tnt) printf("%d%c", a[n][i], i == tnt - 1 ? '\n' : ' ');
    }
    ll n, k, i, j;
    w(t)
    {
        cin >> n >> k;
        if (n == 1 || n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (k == 0)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            cout << a[n][k] << endl;
        }
    }

    return 0;
}