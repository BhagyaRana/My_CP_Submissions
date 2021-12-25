// ---------------------------------TEMPLATE ENDS~---------------------------------
// OPTIMIZATIONS
#pragma GCC optimize("Ofast,03")
#pragma GCC target("sse4,avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
// const int mod = 998244353;

// COMMONLY USED TYPES
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

//LOOPS
#define FOR(i, l, r) for (ll i = l; i <= (r); i++)
#define F0R(i, n) for (ll i = 0; i < (n); i++)
#define FORd(i, a, b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (ll i = (a); i >= 0; i--)
#define trav(x, a) for (auto &x : a)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int((a).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end() //Forward traversal
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

// First Variable Needs to be Ans like ans = max(ans,xyz)
template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}
//                      BE COOL AND FOCUS ON ACCURATE & SIMPLE CODE!
// ---------------------------------TEMPLATE ENDS~---------------------------------

// All Variables Here
#define M 32
// All Functions Here

void solve()
{
    ll n;
    cin >> n;

    vll a(n), b(n);
    bitset<M> arr[n];
    bitset<M> brr[n];

    FOR(i, 0, n - 1)
    {
        cin >> a[i];
        arr[i] = a[i];
    }

    FOR(i, 0, n - 1)
    {
        cin >> b[i];
        brr[i] = b[i];
    }

    // All Bits are Undecided {-1}
    vi state(n, -1);
    // -1 -> Undecided
    // 0 -> Normal
    // 1 -> Flipped

    for (int i = 30; i >= 0; i--)
    {
        // First Check if Bit Can be Set or Not
        bool can_be_set = true;

        FOR(j, 0, n - 1)
        {
            // If Current State is Normal [Front] and ith Bit of Number is Not Set
            if (state[j] == 0 and arr[j][i] == 0)
                can_be_set = false;
            // If Current State is Back [Front] and ith Bit of Number is Not Set
            else if (state[j] == 1 and brr[j][i] == 0)
                can_be_set = false;
            // If in Both States, ith Bit is '0', Its Never Possible to Set that Bit
            else if (arr[j][i] == 0 and brr[j][i] == 0)
                can_be_set = false;
        }

        if (can_be_set == false)
            continue;

        // Control Reaches Here Only, If that Bit can be Set

        // Update the States of Card
        FOR(j, 0, n - 1)
        {
            // If State Already Decided, You can't Change it Further
            if (state[j] != -1)
                continue;
            // Flip the Front Face to Back One
            else if (arr[j][i] == 0)
                state[j] = 1;
            // Make it to Front Face {If ith Bit in B doesnot Contribute to Answer}
            else if (brr[j][i] == 0)
                state[j] = 0;
        }
    }

    ll max_and = (1LL << 30) - 1, flips = 0;

    FOR(i, 0, n - 1)
    {
        // watch(state[i]);
        // If State is 0 -> Not Flipped
        if (state[i] == 1)
        {
            max_and &= b[i];
            flips++;
        }
        else
        {
            max_and &= a[i];
        }
    }

    cout << max_and << " " << flips << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
