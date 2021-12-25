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
#define LMT 1010

ll a[LMT][LMT];
ll b[LMT][LMT];

void inputA(ll r, ll c);

void inputB(ll r, ll c);

// Checks if Both Matrices are Equal
bool EqualMatrix(ll r, ll c);

// Update Only Columns
void Update_Column(ll r, ll c, ll x);

// Update Only Rows
void Update_Row(ll r, ll c, ll x);

// All Functions Here
void solve()
{
    // Since the Limit is Small Brute Forcing All Possible Combinations will Work Fine!
    ll r, c, x;
    cin >> r >> c >> x;

    inputA(r, c);
    inputB(r, c);

    // BASE CASE
    // CASE 1 : x > row && x > column
    if (x > r && x > c)
    {
        if (EqualMatrix(r, c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    // CASE 2 : x > row => Only Sufficent to Change Columns Since Rows can't be Changed
    else if (x > r)
    {
        Update_Column(r, c, x);
        if (EqualMatrix(r, c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    // CASE 3 : x > col => Only Sufficent to Change Rows Since Columns can't be Changed
    else if (x > c)
    {
        Update_Row(r, c, x);
        if (EqualMatrix(r, c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    // MOST IMP CASE 4 : x <= r && x <= c
    else // Brute Force all Possible Scenerios [Update Both Column and Row]
    {
        Update_Column(r, c, x);
        Update_Row(r, c, x);
        if (EqualMatrix(r, c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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

void inputA(ll r, ll c)
{
    for0(i, r)
    {
        for0(j, c)
        {
            cin >> a[i][j];
        }
    }
}

void inputB(ll r, ll c)
{
    for0(i, r)
    {
        for0(j, c)
        {
            cin >> b[i][j];
        }
    }
}

// Checks if Both Matrices are Equal
bool EqualMatrix(ll r, ll c)
{
    for0(i, r)
    {
        for0(j, c)
        {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

// Update Only Columns
void Update_Column(ll r, ll c, ll x)
{
    for0(i, r)
    {
        forc(j, 0, c - x)
        {
            // Both are Equal
            if (a[i][j] == b[i][j])
                continue;
            else
            {
                ll diff = (b[i][j] - a[i][j]);
                a[i][j] = b[i][j];
                ll cnt = 1;
                // Add the Difference to Whole Column
                while (cnt < x)
                {
                    a[i][j + cnt] += diff;
                    cnt++;
                }
            }
        }
    }
}

// Update Only Rows
void Update_Row(ll r, ll c, ll x)
{
    for0(i, c)
    {
        forc(j, 0, r - x)
        {
            if (a[j][i] == b[j][i])
                continue;
            else
            {
                ll diff = (b[j][i] - a[j][i]);
                a[j][i] = b[j][i];
                ll cnt = 1;
                while (cnt < x)
                {
                    a[j + cnt][i] += diff;
                    cnt++;
                }
            }
        }
    }
}