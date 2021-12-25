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
    ll n, m, k, i;
    cin >> n >> m >> k;
    ll a[n], b[n], c[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll l[3], r[3];
    for (i = 0; i < 3; i++)
    {
        cin >> l[i] >> r[i];
    }
    ll x, y, z, tmpk;
    bool flag = 0;
    for (x = l[0]; x <= r[0]; x++)
    {
        for (y = l[1]; y <= r[1]; y++)
        {
            for (z = l[2]; z <= r[2]; z++)
            {
                tmpk = 0;
                for (int j = 0; j < n; j++)
                {
                    if (((x * a[j]) + (y * b[j]) - (c[j] * z)) % m == 0)
                    {
                        tmpk++;
                    }
                }
                if (tmpk == k)
                {
                    cout << x << " " << y << " " << z << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if(flag==0)
    {
        cout << "-1" << endl;
    }

    return 0;
}