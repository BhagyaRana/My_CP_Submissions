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
            cout << n << " -> " << 0 << endl;
            // cout << 0 << endl;
            continue;
        }

        ll nice_swp = 0;
        ll sum_half = sum / 2;
        // watch(sum_half);
        ll suffix = 0;
        // Probable Swapping Possible
        ll i;
        for (i = n; i >= 1; i--)
        {
            suffix += i;
            nice_swp++;
            if (suffix >= sum_half)
                break;
        }
        // cout << suffix << endl;
        watch(nice_swp);
        watch(suffix);
        watch(i);

        if (suffix == sum_half)
        {
            i--;
            cout << "Suffix=Half_Sum\n";
            watch(i);
            nice_swp += (i * (i - 1)) / 2;
            inp -= i;
            watch(inp);
            nice_swp += (inp * (inp - 1)) / 2;
            // cout << "here" << endl;
        }

        cout << n << " -> " << nice_swp << endl;
    }

    return 0;
}