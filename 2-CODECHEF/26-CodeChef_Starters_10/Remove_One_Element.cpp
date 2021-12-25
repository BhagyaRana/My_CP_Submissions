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

// DEBUG FUNCTIONS
// Single Variable
template <typename T>
void __p(T a)
{
    cout << a;
}
// Pair
template <typename T, typename F>
void __p(pair<T, F> a)
{
    cout << "{";
    __p(a.first);
    cout << ",";
    __p(a.second);
    cout << "}";
}
// Vector
template <typename T>
void __p(std::vector<T> a)
{
    cout << "{";
    for (auto it = a.begin(); it < a.end(); it++)
        __p(*it), cout << ",}"[it + 1 == a.end()];
}
// Set
template <typename T>
void __p(std::set<T> a)
{
    cout << "{";
    for (auto it = a.begin(); it != a.end();)
    {
        __p(*it);
        cout << ",}"[++it == a.end()];
    }
}
// MultiSet
template <typename T>
void __p(std::multiset<T> a)
{
    cout << "{";
    for (auto it = a.begin(); it != a.end();)
    {
        __p(*it);
        cout << ",}"[++it == a.end()];
    }
}
// Map
template <typename T, typename F>
void __p(std::map<T, F> a)
{
    cout << "{\n";
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout << "\n";
    }
    cout << "}\n";
}

template <typename T, typename... Arg>
void __p(T a1, Arg... a)
{
    __p(a1);
    __p(a...);
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : ";
    __p(arg1);
    cout << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    int bracket = 0, i = 0;
    for (;; i++)
        if (names[i] == ',' && bracket == 0)
            break;
        else if (names[i] == '(')
            bracket++;
        else if (names[i] == ')')
            bracket--;
    const char *comma = names + i;
    cout.write(names, comma - names) << " : ";
    __p(arg1);
    cout << " | ";
    __f(comma + 1, args...);
}

#define trace(...) cout << "Line:" << __LINE__ << " ", __f(#__VA_ARGS__, __VA_ARGS__)

// DEBUG FUNCTIONS END

//                      BE COOL AND FOCUS ON ACCURATE & SIMPLE CODE!
// ---------------------------------TEMPLATE ENDS~---------------------------------

// All Variables Here

// All Functions

bool ok(vll a, vll b, ll d)
{
    ll n = a.size();
    for (int i = 0; i < n; i++)
    {
        if ((b[i] - a[i]) != d)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;

    ll a_sum = 0, b_sum = 0;

    vll a(n);
    for (auto &x : a)
    {
        cin >> x;
        a_sum += x;
    }

    vll b(n - 1);
    for (auto &y : b)
    {
        cin >> y;
        b_sum += y;
    }

    sort(all(a));
    sort(all(b));

    if (n == 2)
    {
        ll ans = 1e9;
        if (b[0] - a[0] > 0)
            ans = min(ans, b[0] - a[0]);
        if (b[0] - a[1] > 0)
            ans = min(ans, b[0] - a[1]);
        cout << ans << endl;
        return;
    }

    vll q;

    for (int i = 0; i < n; i++)
    {
        // Let a[i] be Removed One
        ll t = a_sum;
        t -= a[i];
        // t + (n-1)*x = b_sum
        ll k = b_sum - t;

        if (k > 0 && (k % (n - 1) == 0))
        {
            ll x = k / (n - 1);
            // cout << x << endl;

            vll g = a;
            g.erase(g.begin() + i);

            // __p(g);
            // __p(b);

            if (ok(g, b, x))
            {
                q.push_back(x);
            }
        }
    }

    cout << *min_element(all(q)) << endl;

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
