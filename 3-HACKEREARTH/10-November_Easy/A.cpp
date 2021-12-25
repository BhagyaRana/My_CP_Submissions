// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

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

// to be used with algorithms that processes a container
// Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

//FIND
// find if a given value is present in a container. Container version.
// Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

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

int solve(int arr[], int n, int k)
{
    int start = -1;
    int end = -1;
    int min = 1e6;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = i; j < n && (j - i + 1) < min; j++)
        {
            cur += arr[j];
            if (cur == k)
            {
                start = i;
                end = j;
                min = end - start + 1;
                break;
            }
        }
    }
    if (start == -1 || end == -1)
    {
        return -1;
    }
    else
    {
        return min;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        int a[n] = {0};
        ll pos_sum = 0;
        ll neg_sum = 0;

        vi p;
        vi n1;

        for0(i, n)
        {
            cin >> a[i];
            if (a[i] > 0)
            {
                pos_sum += a[i];
                p.pb(a[i]);
            }
            else
            {
                if (a[i] < 0)
                {
                    neg_sum += abs(a[i]);
                    n1.pb(abs(a[i]));
                }
            }
        }

        if (pos_sum == neg_sum)
        {
            cout << 0 << endl;
            continue;
        }

        // neg_sum = abs(neg_sum);

        if (abs(pos_sum - neg_sum) % 2 == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            ll diff = abs(pos_sum - neg_sum) / 2;
            // watch(diff);
            ll final = 1e6;

            if (p.size() > 0)
            {
                const int sz = p.size();
                int arr[sz] = {0};
                for0(i, sz)
                {
                    arr[i] = p[i];
                }

                ll ans1 = solve(arr, sz, diff);

                if (ans1 != -1)
                {
                    final = min(final, ans1);

                    if (pos_sum % 2 == 0)
                    {
                        final = min(final, sz - ans1);
                    }
                }

                // cout << "pos" << endl;
                // cout << ans1 << endl;
            }

            if (n1.size() > 0)
            {
                const int sz = n1.size();
                int arr2[sz] = {0};
                for0(i, sz)
                {
                    arr2[i] = n1[i];
                }

                ll ans2 = 0;
                ans2 = solve(arr2, sz, diff);

                if (ans2 != -1)
                {
                    final = min(final, ans2);

                    if (neg_sum % 2 == 0)
                    {
                        final = min(final, sz - ans2);
                    }
                }

                // cout << "neg" << endl;
                // cout << ans2 << endl;
            }
            if(final!=1e6)
                cout << final << endl;
            else
            {
                cout << -1 << endl;
            }
            
        }
    }

    return 0;
}
