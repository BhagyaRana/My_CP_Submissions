// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
// const int mod = 998244353;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end() //Forward traversal

//FIND
// find if a given value is present in a container. Container version.
// Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define endl "\n"

// COMMONLY USED TYPES
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

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

// All Variables Here

// All Functions Here
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    // Bxy + Dx + Ey + F = 0
    // -2xy + mx + ny - k = 0;
    //CASE 1 : mn - (-2*-k)
    if ((m * n) == (2 * k))
    {
        // If n is multiple of 2
        if (m % 2 == 0)
        {
            cout << "Yes" << endl;
            return;
        }
        if (n % 2 == 0)
        {
            // Avoid Case where x = n/2
            cout << "No" << endl;
            // cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
        return;
    }
    // CASE 2 : Find All Divisors of
    else
    {
        ll rhs = (n * m) - (2 * k);
        ll myn = abs(rhs);
        vll div;
        for1(i, sqrt(myn))
        {
            if (myn % i == 0)
            {
                if (myn / i == i)
                {
                    div.pb(i);
                }
                else
                {
                    div.pb(myn / i);
                    div.pb(i);
                }
            }
        }

        for (auto x : div)
        {
            ll d1 = x;

            ll num1 = n - d1;
            ll den1 = m - (rhs / d1);
            if (num1 % 2 == 0 && den1 % 2 == 0)
            {
                ll tx = num1 / 2;
                ll ty = den1 / 2;
                if (tx >= 0 && tx <= n && ty >= 0 && ty <= m)
                {
                    if (n % 2 == 0 && tx == n / 2)
                    {
                        goto skip;
                    }
                    cout << "Yes" << endl;
                    return;
                }
            skip:;
            }

            ll d2 = -1 * (x);
            ll num2 = n - d2;
            ll den2 = m - (rhs / d2);
            if (num2 % 2 == 0 && den2 % 2 == 0)
            {
                ll tx2 = num2 / 2;
                ll ty2 = den2 / 2;
                if (tx2 >= 0 && tx2 <= n && ty2 >= 0 && ty2 <= m)
                {
                    if (n % 2 == 0 && tx2 == n / 2)
                    {
                        goto skip2;
                    }
                    cout << "Yes" << endl;
                    return;
                }
            skip2:;
            }
        }

        cout << "No" << endl;
        return;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
