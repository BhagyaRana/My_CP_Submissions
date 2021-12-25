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
void pairsort(ll a[], ll b[], ll n)
{
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        v[i] = make_pair(a[i], b[i]);
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        a[i] = v[i].first;
        b[i] = v[i].second;
    }
    return;
}

void solve()
{
    string s;
    cin >> s;

    bool freq[26];
    vector<pair<int, int>> v;
    vector<pair<int, int>> ans[26];
    int occur[26];

    F0R(i, 26)
    {
        occur[i] = 0;
    }

    int cnt = 1000;
    for (auto ch : s)
    {
        if (occur[ch - 'a'] == 1000)
        {
            occur[ch - 'a'] = cnt;
            cnt--;
        }
    }

    queue<pair<int, int>> q;

    q.push({0, 0});
    q.push({1, 0});
    q.push({1, 1});
    q.push({0, 1});
    q.push({-1, 1});

    q.push({-1, 0});
    q.push({-1, -1});
    q.push({0, -1});
    q.push({1, -1});
    q.push({2, -1});

    q.push({2, 0});
    q.push({2, 1});
    q.push({2, 2});
    q.push({1, 2});
    q.push({0, 2});

    q.push({-1, 2});
    q.push({-2, 2});
    q.push({-2, 1});
    q.push({-2, 0});
    q.push({-2, -1});

    q.push({-2, -2});
    q.push({-1, -2});
    q.push({0, -2});
    q.push({1, -2});
    q.push({2, -2});

    q.push({3, -2});

    map<int, int> mp;
    for (int i = 0; i < 26; i++)
    {
        mp[i]++;
    }

    for (auto ch : s)
    {
        mp[ch - 'a']++;
    }

    vector<pair<int, int>> tmp(26);
    for (int i = 0; i < 26; i++)
    {
        tmp[i] = {1000 - (mp[i] - 1), i};
    }

    vector<tuple<int, int, int>> tmp2;
    for (int i = 0; i < 26; i++)
    {
        tmp2.pb(make_tuple(tmp[i].first, occur[tmp[i].second], tmp[i].second));
    }

    sort(all(tmp2));

    for (int i = 0; i < 26; i++)
    {
        pair<int, int> pp = q.front();
        q.pop();
        ans[get<2>(tmp2[i])].pb(pp);
    }

    for (int i = 0; i < 26; i++)
    {
        for (auto p : ans[i])
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // If No Test Case, Then Comment it!
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}