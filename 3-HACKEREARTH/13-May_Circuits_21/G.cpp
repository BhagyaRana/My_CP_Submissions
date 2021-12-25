// ---------------------------------TEMPLATE ENDS~---------------------------------
// OPTIMIZATIONS
#pragma GCC optimize("Ofast,03")
#pragma GCC target("sse4,avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename num_t>
struct ordered_multiset
{
    ordered_set<pair<num_t, int>> vals;
    set<pair<num_t, int>> best; /* start at -1 */

    /* helper, find the lowest value that represents the element */
    int findbest(num_t val)
    {
        return (*best.upper_bound(make_pair(val - 1, 0))).second;
    }

    /* is element in set */
    bool contains(num_t val)
    {
        return vals.find(make_pair(val, -1)) != vals.end();
    }

    void insert(num_t val)
    {
        if (contains(val))
        { /* already in, update lowest value and insert a new one */
            int loc = findbest(val);
            best.erase(make_pair(val, loc));
            best.insert(make_pair(val, loc - 1));
            vals.insert(make_pair(val, loc - 1));
        }
        else
        { /* make lowest value -1 and insert it */
            best.insert(make_pair(val, -1));
            vals.insert(make_pair(val, -1));
        }
    }

    void erase(num_t val)
    { /* erases one */
        if (!contains(val))
            return; /* not in */
        num_t loc = findbest(val);

        /* remove the element and its best */
        best.erase(make_pair(val, loc));
        vals.erase(make_pair(val, loc));
        if (loc != -1)
            best.insert(make_pair(val, loc + 1)); /* more elements in set, update best */
    }

    /* unmodified functions */
    num_t find_by_order(int k) { return (*vals.find_by_order(k)).first; }
    int order_of_key(num_t k) { return vals.order_of_key(make_pair(k - 1, 0)); }
    pair<num_t, int> *begin() { return vals.begin(); }
    pair<num_t, int> *end() { return vals.end(); }
    pair<num_t, int> *rbegin() { return vals.rbegin(); }
    pair<num_t, int> *rend() { return vals.rend(); }
    int size() { return vals.size(); }
    void clear()
    {
        vals.clear();
        best.clear();
    }
    int count(num_t k) { return vals.order_of_key(k + 1) - vals.order_of_key(k); }
    pair<num_t, int> *lower_bound(num_t k) { return vals.lower_bound(make_pair(k - 1, 0)); }
    pair<num_t, int> *upper_bound(num_t k) { return vals.upper_bound(make_pair(k, 0)); }
};

/* ------------------------------------------------------------------------ COMMENTS ------------------------------------------------------------------------ */
/* supports things like k-th smallest element and find index of element in set */
/* all in pretty good O(lgn) */

/* example usage */
ordered_set<int> os;

/* extra functions (in addition to std::set operations):
	find_by_order(k) - returns a pointer to the k-th smallest element in the set (zero-indexed)
	order_of_key(k) - returns the number of elements in the set less than k (if k is in the set, this is the index of it)
*/

/* gfg: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/ 
	examples:
	set = {1, 5, 6, 17, 88}
	find_by_order(1) - same as set[1] -> pointer to 5
	find_by_order(4) - same as set[4] -> pointer to 88
	order_of_key(6) -> 2
	order_of_key(88) -> 4
	order_of_key(400) -> 5
	order_of_key(0) -> 0
*/

void solve()
{
    ll m, n, x, q;
    cin >> m >> n >> x >> q;
    ll tot = n * m;

    // vector<vi> mat(m + 1, vi(n + 1, 0));

    ordered_set<ll> os;

    // map<ll, ll> mp;

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            // mat[i][j] = i + j + x;
            // mp[i + j]++;
            os.insert(i + j);
        }
    }

    int q_type;

    F0R(tt, q)
    {
        cin >> q_type;
        if (q_type == 1)
        {
            ll r, c1, c2;
            cin >> r >> c1 >> c2;
            FOR(j, c1, c2)
            {
                os.erase(r + j);
                // mp[r + j]--;
                // mat[r][j] = -1;
                tot--;
            }
        }
        else if (q_type == 2)
        {
            ll c, r1, r2;
            cin >> c >> r1 >> r2;
            FOR(i, r1, r2)
            {
                os.erase(r + j);
                // mp[i + c]--;
                // mat[i][c] = -1;
                tot--;
            }
        }
        else
        {
            ll k;
            cin >> k;

            if (k > tot)
            {
                cout << "-1\n";
                continue;
            }

            cout << os.find_by_order(k+1) << endl;

            // ll ans = 0;
            // ll tmp = k;

            // for (auto ele : mp)
            // {
            //     if (ele.second < tmp)
            //     {
            //         tmp -= ele.second;
            //     }
            //     else
            //     {
            //         ans = ele.first;
            //         break;
            //     }
            // }

            // cout << ans + x << endl;
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
