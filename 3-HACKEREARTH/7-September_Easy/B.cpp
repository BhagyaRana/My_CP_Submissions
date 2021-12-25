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
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << endl;
    }
    else
    {
        if (n >= 3 && n <= 11)
        {
            cout << 2 << endl;
        }
        else
        {
            if (n >= 12 && n <= 29)
            {
                cout << 3 << endl;
            }
            else
            {
                if (n >= 30 && n <= 82)
                {
                    cout << 4 << endl;
                }
                else
                {
                    if (n >= 83 && n <= 245)
                    {
                        cout << 5 << endl;
                    }
                    else
                    {
                        int ans = 0;
                        while (n)
                        {
                            n = n / 3;
                            ans++;
                        }
                        cout << ans << endl;
                    }
                }
            }
        }
    }

    return 0;
}