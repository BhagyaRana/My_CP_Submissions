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
const int mod = 1000000007;

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define LIMIT 500001

ll fact[LIMIT];

ll power(ll x, ll y, ll p)
{
    x %= p;
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll nCrModFermat(ll n, ll r, ll m)
{
    if (r == 0)
        return 1;

    return (((fact[n] * modInverse(fact[n - r], mod)) % m) * modInverse(fact[r], mod)) % m;
}

// All Functions Here
void doitonce()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int j = 2; j < LIMIT; j++)
    {
        fact[j] = (1ll * fact[j - 1] * j) % mod;
    }
}

// All Variables Here

int main()
{
    b_v_r();
    doitonce(); // factorial intialised

    w(t)
    {
        ll n;
        cin >> n;
        ll arr[n];
        map<ll, ll> fre;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            fre[arr[i]]++;
        }

        ll prefix[n + 2];
        ll suffix[n + 2];

        for (int i = 0; i <= n + 1; i++)
        {
            prefix[i] = 1;
            suffix[i] = 1;
        }

        for (auto each : fre)
        {
            ll total = 1;
            for (int k = 1; k <= each.second; k++)
            {
                total += nCrModFermat(each.second, k, mod);
                total %= mod;
                prefix[k] *= total;
                prefix[k] %= mod;
            }
            suffix[each.second + 1] *= total;
            suffix[each.second + 1] %= mod;
        }

        //Multiply Prefix with Suffix
        ll mul = 1;
        for (int i = 1; i <= n; i++)
        {
            mul *= suffix[i];
            mul %= mod;

            prefix[i] *= mul;
            prefix[i] %= mod;
        }

        for (int i = 1; i <= n; i++)
        {
            ll ans, ans1, total;
            ans = 0;
            total = 1;

            for (int j = 1; j <= fre[i]; j++)
            {
                ll var;
                ans1 = nCrModFermat(fre[i], j, mod);
                var = ans1;
                total += var;
                total %= mod;

                prefix[j] = (prefix[j] * modInverse(total, mod)) % mod;
                ans1 *= prefix[j];
                ans1 %= mod;

                prefix[j] = (prefix[j] * (total - var + mod) % mod) % mod;
                ans += ans1;
                ans %= mod;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}