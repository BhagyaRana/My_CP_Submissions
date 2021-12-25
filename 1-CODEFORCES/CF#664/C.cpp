#pragma GCC optimize("O2")

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

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

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

int main()
{
    b_v_r();

    ll n, m;

    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);

    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];

    // Brute Force Solution
    ll f, tmp, j, ans = 0;
    for (ans = 0; ans <= 512; ans++)
    {
        // flag = 1
        f = 1;

        for (ll i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                tmp = (a[i] & b[j]) | ans;
                if (tmp <= ans)
                    break;
            }
            // If No j Found to make ans
            if (j == m)
            {
                f = 0;
                break;
                // no use of checking other i's
            }
        }
        // if ans is found
        if (f)
            break;
    }

    cout << ans << endl;

    return 0;
}
