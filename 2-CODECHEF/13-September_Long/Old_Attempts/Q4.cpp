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

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();
    ll i, j, k;
    w(t)
    {
        ll n;
        cin >> n;
        // Sequence S : 1 2 3 4 5 .. .. .. N

        ll sum = n * (n + 1) / 2;
        if (sum & 1)
        {
            cout << 0 << endl;
            continue;
        }

        vector<ll> v(n + 1);
        vector<ll> lf(n + 1);
        vector<ll> rgh(n + 1);
        // vector<ll> mydiff(n + 1);
        // vector<ll> mydiff2(n - 1);

        for (i = 1; i <= n; i++)
        {
            v[i] = i;
            lf[i] = (i * (i + 1)) / 2;
            rgh[i] = sum - lf[i];
            // watch2(lf[i], rgh[i]);
            // mydiff[i] = rgh[i] - lf[i];
        }

        ll nice_swp = 0, diff;
        // for (i = 0; i < n - 1; i++)
        // {
        //     mydiff2[i] = mydiff[i + 1];
        // }
        // sort(mydiff2.begin(), mydiff2.end());

        for (i = 1; i < n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                diff = (v[j] - v[i]);
                for (k = 1; k < n; k++)
                {
                    if (k < j && k >= i)
                    {
                        if (lf[k] + diff == rgh[k] - diff)
                        {
                            nice_swp++;
                            break;
                        }
                    }
                    else
                    {
                        //k >=j
                        if (lf[k] == rgh[k])
                        {
                            nice_swp++;
                            break;
                        }
                    }
                }
            }
        }
        cout << nice_swp << endl;
    }

    return 0;
}