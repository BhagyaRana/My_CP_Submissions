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
vector<ll> divisors(ll n)
{
    vector<ll> x;
    ll s = sqrt(n);
    for (ll i = 1; i <= s; i++)
    {
        if (n % i == 0)
        {
            // check if divisors are equal
            if (n / i == i)
                x.push_back(i);
            else
            {
                x.push_back(i);
                x.push_back(n / i);
            }
        }
    }
    x.push_back(n);
    return x;
}

void solve()
{
    ll n, m, k;

    cin >> n >> m >> k;

    if (k > (n * m))
    {
        cout << "No" << endl;
        return;
    }
    else
    {
        // https://www.alpertron.com.ar/METHODS.HTM

        ll B = -2, D = m, E = n, F = -1 * k;
        ll de_bf = ((D * E) - (B * F));

        if (de_bf == 0)
        {
            if ((E & 1) && (D & 1))
            {
                
                cout << "No" << endl;
            }
            else
            {
                cout << "No" << endl;
                ll nx = (-1 * E) / B;
                ll ny = (-1 * D) / B;
                if (nx >= 0 && nx <= n)
                {
                    if (ny >= 0 && ny <= m)
                    {
                        cout << "Yes" << endl;
                        return;
                    }
                    else
                    {
                        cout << "No" << endl;
                        return;
                    }
                }
                else if (ny >= 0 && ny <= m)
                {
                    cout << "Yes" << endl;
                    return;
                }
                cout << "No" << endl;
                return;
            }
        }
        else
        {
            vll div = divisors(abs(de_bf));
            ll x, y;
            for (auto el : div)
            {
                x = el - E;
                y = (de_bf / el) - D;
                if ((x % 2 == 0) && (y % 2 == 0))
                {
                    ll nx = x / B;
                    ll ny = y / B;
                    if (nx >= 0 && nx <= n && ny >= 0 && ny <= m)
                    {

                        if (nx == n / 2)
                        {
                            continue;
                        }
                        watch2(nx, ny);
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
            cout << "No" << endl;
            return;
        }
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