// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 998244353;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
// reverse 0 based.
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
// reverse 1 based
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

// COMMONLY USED TYPES
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef map<int, int> mii;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here
ll powmod(ll a, ll b, ll p)
{
    a %= p;
    if (a == 0)
        return 0;
    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        { // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2; // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p)
{
    return powmod(a, p - 2, p);
}

ll pqinv(ll p, ll q)
{
    // (p / q) = (p*(q^-1))%mod
    return ((p) % mod * (inv(q, mod)) % mod) % mod;
}

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    w(t)
    {
        ll n;
        cin >> n;
        ll a[n] = {0};
        ll den = 1;

        for0(i, n)
        {
            cin >> a[i];
            den = (den * (a[i] + 1)) % mod;
        }

        if (n == 1)
        {
            // To be Covered
            if (a[0] & 1)
            {
                // 1 + 2 + ..[half] + [half] + .. 2 + 1
                ll half = a[0] / 2;
                ll num = 0;
                num = ((num) % mod + (half * (half + 1)) % mod) % mod;
                cout << pqinv(num, den) << endl;
            }
            else
            {
                // 1 + 2 + ..[half-1]+ [mid] + [half-1].. 2 + 1
                ll half = a[0] / 2;
                ll num = 0;
                num = ((num) % mod + (half) % mod) % mod;
                half--;
                num = ((num) % mod + (half * (half + 1)) % mod) % mod;
                cout << pqinv(num, den) << endl;
            }
            continue;
        }

        sort(a, a + n);

        if (a[0] == 0 || a[0] == 1)
        {
            cout << 0 << endl;
            continue;
        }
        else if (a[0] == 2)
        {
            ll cnt = 0;
            ll val = 1;
            for (int i = 1; i < n; i++)
            {
                cnt += (a[i] - 1);
            }
            ll num = 0;
            num = ((num) % mod + (val * cnt) % mod) % mod;
            // watch2(num, den);
            cout << pqinv(num, den) << endl;
            continue;
        }
        else if (a[0] == 3)
        {
            ll val = 1;
            ll prod = 1;
            for (int i = 1; i < n; i++)
            {
                prod = ((prod)%mod*(a[i]-1)%mod)%mod;
            }

            ll num = 0;
            num = ((num) % mod + (2 * val * prod) % mod) % mod;
            // watch2(num, den);
            cout << pqinv(num, den) << endl;
            continue;
        }

        int st = 0;
        ll lim = (a[0] - 1) / 2;
        ll num = 0;
        // cout << "STRICTLY GREATER THAN" << endl;

        // Strictly Greater than Case  [val] < [No Of Elements]
        for (int i = st; i < n; i++)
        {
            // i th Element is Selected

            if (a[i] & 1)
            {
                // 1 2 ... [half] [half] ... 2 1
                ll half = (a[i] / 2);
                for (int val = 1; val <= min(half, lim); val++)
                {
                    ll cnt = 0;
                    for (int j = st; j < n; j++)
                    {
                        if (j != i)
                        {
                            if ((a[j] - ((2 * val) + 1)) > 0)
                                cnt += (a[j] - ((2 * val) + 1));
                        }
                    }
                    // Above [1] [2] & Below [1] & [2]
                    // watch2(val, cnt);
                    num = ((num) % mod + (2 * val * cnt) % mod) % mod;
                }
            }
            else
            {
                // 1 2 ... [half-1] [half] [half-1] ... 2 1
                ll half = (a[i] / 2);
                
                for (int val = 1; val <= min(half - 1, lim); val++)
                {
                    ll cnt = 0;
                    for (int j = st; j < n; j++)
                    {
                        if (j != i)
                        {
                            if ((a[j] - ((2 * val) + 1)) > 0)
                                cnt += (a[j] - ((2 * val) + 1));
                        }
                    }
                    // watch2(val, cnt);
                    // Above [1] [2] & Below [1] & [2]
                    num = ((num) % mod + (2 * val * cnt) % mod) % mod;
                }

                ll val = half;
                ll cnt = 0;
                for (int j = st; j < n; j++)
                {
                    if (j != i)
                    {
                        if ((a[j] - ((2 * val) + 1)) > 0)
                            cnt += (a[j] - ((2 * val) + 1));
                    }
                }
                num = ((num) % mod + (val * cnt) % mod) % mod;
            }
        }

        // All are Equal Case
        // cout << "EQUAL" << endl;
        if (a[0] & 1)
        {
            // 1 2 ... [half] [half] ... 2 1
            // watch2(num, den);
            ll half2 = a[0] / 2;
            ll cnt = 2 * (n - 1);
            for (int i = 1; i <= half2; i++)
            {
                num = ((num) % mod + (2 * i * cnt) % mod) % mod;
            }
            // watch2(num, den);
            cout << pqinv(num, den) << endl;
        }
        else
        {
            ll half2 = a[0] / 2;
            ll cnt = 2 * (n - 1);
            for (int i = 1; i <= half2 - 1; i++)
            {
                num = ((num) % mod + (2 * i * cnt) % mod) % mod;
            }
            num = ((num) % mod + (half2 * cnt) % mod) % mod;
            // watch2(num, den);
            cout << pqinv(num, den) << endl;
        }
    }
    return 0;
}
