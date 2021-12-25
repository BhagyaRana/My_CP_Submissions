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
        ll inp = n;
        ll sum = (n * (n + 1)) / 2;
        if (sum & 1)
        {
            // cout << n << " -> " << 0 << endl;
            cout << 0 << endl;
            continue;
        }

        ll nice_swp = 0;
        ll tmp = (2 * n) + 1;
        ll disc = (ll)sqrt(((tmp * tmp) - (4 * sum)));
        ll r1 = 0;
        ll p = (tmp - disc) / 2;
        if (p > 0)
        {
            r1 = p;
        }
        else
        {
            r1 = ((tmp + disc) / 2);
        }
        // watch(r1);
        ll old_sum = (r1 * (tmp - r1)) / 2;
        // watch(old_sum);
        // watch(sum / 2);
        if (old_sum != (sum / 2))
        {
            // r1++;
            if (old_sum < (sum / 2))
                r1++;
            nice_swp += r1;
        }
        else
        {

            nice_swp += r1;
            // r1++;
        }

        // ll sr1 = (r1 * (tmp - r1)) / 2;
        // watch(nice_swp);
        // watch(sr1);

        if (old_sum == (sum / 2))
        {
            // cout << "Suffix=Half_Sum\n";
            // watch(r1);
            nice_swp += (r1 * (r1 - 1)) / 2;
            inp -= r1;
            // watch(inp);
            nice_swp += (inp * (inp - 1)) / 2;
            // cout << "here" << endl;
        }

        // cout << n << " -> " << nice_swp << endl;
        cout << nice_swp << endl;
    }

    return 0;
}