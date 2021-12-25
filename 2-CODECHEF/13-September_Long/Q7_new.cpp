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
string str[5] = {"", "0", "10", "110", "0110"};
ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

// All Variables Here

int main()
{
    b_v_r();
    int k;
    cin >> k;
    w(t)
    {
        int n;
        cin >> n;
        
        int res;
        if (n % 4 == 0 || n % 3 == 0)
        {
            res = 0;
        }
        else
        {
            res = 1;
        }
        // cout << res << endl;
        // cout << n << " -> " << res << endl;

        string ans = "";
        for (int i = 0; i < n / 4; i++)
        {
            ans += str[4];
        }
        int temp;
        if (n % 4 == 1)
        {
            ans = str[1] + ans;
        }
        else if (n % 4 == 2)
        {
            ans += str[2];
        }
        else if (n % 4 == 3)
        {
            ans = str[3] + ans;
        }

        ll a = 0, b = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i - 1] == (char)'1')
            {
                b += power(i, k);
            }
            else
            {
                a += power(i, k);
            }
        }

        cout << n << " -> " << abs(b - a) << endl;
        // cout << abs(b - a) << endl;

        cout << ans << endl;
    }

    return 0;
}