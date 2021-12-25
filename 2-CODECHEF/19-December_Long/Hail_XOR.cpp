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
#define M 32

// All Functions Here

void solve()
{
    ll n, x, fxor = 0, cntsetbit = 0;

    cin >> n >> x;

    bitset<M> b[n];

    ll arr[n] = {0};

    for0(i, n)
    {
        cin >> arr[i];
        b[i] = arr[i];
        cntsetbit += b[i].count();
        fxor ^= arr[i];
    }

    bitset<M> f = fxor;
    ll pairs = (cntsetbit - f.count()) / 2;

    int v2 = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (f[i] == 1 && (b[n - 1][i] != 1))
        {
            v2++;
        }
    }

    if (x >= pairs + v2)
    {
        if (n != 2)
        {
            for0(i, n - 1)
            {
                cout << 0 << " ";
            }
            cout << fxor << endl;
        }
        else
        {
            ll diff = x - (pairs + v2);
            if ((diff % 2) == 0)
            {
                cout << 0 << " " << fxor << endl;
            }
            else
            {
                ll n1 = 1;

                if (f[0] == 1)
                {
                    f[0] = 0;
                }
                else
                {
                    f[0] = 1;
                }

                ll n2 = f.to_ulong();

                cout << n1 << " " << n2 << endl;
            }
        }
    }
    else
    {

        ll xcnt = x;

        for (int i = 0; i < n && (xcnt > 0); i++)
        {
            for (int p = 31; p >= 0 && (xcnt > 0); p--)
            {
                if (b[i][p] == 1)
                {
                    bool found = false;
                    for (int j = i + 1; j < n && (xcnt > 0); j++)
                    {
                        if (b[j][p] == 1)
                        {
                            found = true;
                            b[i][p] = 0;
                            b[j][p] = 0;
                            arr[i] = b[i].to_ulong();
                            arr[j] = b[j].to_ulong();
                            xcnt--;
                            break;
                        }
                    }
                    if (found == false)
                    {
                        b[i][p] = 0;
                        b[n - 1][p] = 1;
                        arr[i] = b[i].to_ulong();
                        arr[n - 1] = b[n - 1].to_ulong();
                        xcnt--;
                    }
                }
            }
        }

        for0(i, n)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
