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

// All Functions Here

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    w(t)
    {
        string s;
        cin >> s;
        int n = s.length();
        string odd;
        string even;
        string numo;
        string nume;
        int asc;
        for0(i, n)
        {
            if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
            {
                asc = s[i] - '0';
                if (asc & 1)
                {
                    numo += s[i];
                }
                else
                {
                    nume += s[i];
                }

                // num += s[i];
            }
            else
            {
                asc = s[i] - 'a';
                if (asc & 1)
                {
                    odd += s[i];
                }
                else
                {
                    even += s[i];
                }
            }
        }
        sort(all(odd));
        sort(all(even));
        sort(all(numo));
        sort(all(nume));
        // string t;
        // string t2;
        // int l1 = nume.length();
        // for0(i, l1)
        // {
        //     if ((nume[i] - '0') == 0)
        //     {
        //         t2 += nume[i];
        //     }
        //     else
        //     {
        //         t += nume[i];
        //     }
        // }
        // sort(all(num));
        if (odd.length() != 0)
        {
            cout << odd;
        }
        if (even.length() != 0)
        {
            cout << even;
        }
        if (numo.length() != 0)
        {
            cout << numo;
        }
        if (nume.length() != 0)
        {
            cout << nume;
        }

        // if (t.length() != 0)
        // {
        //     cout << t;
        // }
        // if (t2.length() != 0)
        // {
        //     cout << t2;
        // }
        cout << endl;
        // cout << odd << even << numo << t << t2 << endl;
    }

    return 0;
}
