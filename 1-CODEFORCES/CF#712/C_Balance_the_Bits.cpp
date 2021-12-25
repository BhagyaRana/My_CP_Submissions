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
#define FOR(i, l, r) for (int i = l; i <= (r); i++)
#define F0R(i, n) for (int i = 0; i < (n); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a); i >= 0; i--)
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

// All Functions Here

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // Count of Number of Zeros and Count of Ones
    int c0 = 0, c1 = 0;
    F0R(i, n)
    {
        if (s[i] == '0')
            c0++;
        else
            c1++;
    }

    // Balance Parenthesis -> c1/c0 is odd => No Chance
    if ((c1 & 1) || (c0 & 1))
    {
        cout << "NO\n";
        return;
    }

    // If First and Least Character of String is "0"
    if (s[0] == '0' || s[n - 1] == '0')
    {
        cout << "NO\n";
        return;
    }
    string a;
    string b;
    // Answer is Definately Yes
    int cnt = 0;
    F0R(i, n)
    {
        if (s[i] == '0')
        {
            if (cnt & 1)
            {
                a += ')';
                b += '(';
                cnt++;
            }
            else
            {
                a += '(';
                b += ')';
                cnt++;
            }
        }
        else
        {
            if (c1)
            {
                a += '(';
                b += '(';
                c1 -= 2;
            }
            else
            {
                a += ')';
                b += ')';
            }
        }
    }
    
    cout << "YES\n";
    cout << a << "\n";
    cout << b << "\n";

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
