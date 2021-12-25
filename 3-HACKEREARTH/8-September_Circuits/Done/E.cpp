#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

#define pll pair<ll, ll>

// All Functions Here
bool mycmp(pll A, pll B)
{
    double d1 = (double)(A.second) / (double)(A.first);
    double d2 = (double)(B.second) / (double)(B.first);
    return d1 >= d2;
}

// All Variables Here

int main()
{
    b_v_r();

    int n;

    w(t)
    {
        cin >> n;

        ll mat1[n + 1] = {0}, mat2[n + 1] = {0}, mat3[n + 1] = {0};

        ll i, j;

        for (i = 1; i <= n; i++)
        {
            cin >> mat1[i];
        }

        for (i = 1; i <= n; i++)
        {
            cin >> mat2[i];
        }

        vector<pll> v;

        for (i = 1; i <= n; i++)
        {
            cin >> mat3[i];
            mat3[i] *= mat2[i];
            v.push_back({mat1[i], mat3[i]});
        }

        sort(v.begin(), v.end(), mycmp);

        ll ans = 1e9 + 10;

        ll f1 = 0LL, t1;

        ll cprod = 0LL;

        for (j = 1; j <= n - 1; j++)
        {
            cprod += v[j].second;
            cprod %= mod;
        }

        for (i = 0; i <= n - 2; i++)
        {
            f1 += (v[i].first * cprod) % mod;
            f1 %= mod;
            cprod = (cprod - v[i + 1].second + mod) % mod;
        }

        if (f1 < ans)
            ans = f1;

        cout << ans << endl;
    }

    return 0;
}