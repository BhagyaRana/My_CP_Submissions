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
    w(t)
    {
        ll n, i, min = 1e9 + 1;
        cin >> n;
        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < min)
                min = a[i];
        }

        vector<ll> v;
        for (i = 0; i < n; i++)
        {
            if (a[i] % min == 0)
            {
                v.emplace_back(a[i]);
                a[i] = -1;
            }
        }

        sort(v.begin(), v.end());

        int j = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                a[i] = v[j];
                j++;
            }
        }

        bool f = true;
        for (i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}