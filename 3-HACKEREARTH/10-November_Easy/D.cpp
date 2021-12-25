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
// In-place rotates s towards left by d
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
    leftrotate(s, s.length() - d);
}

bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int k;
    cin >> k;
    string x;
    string y;
    cin >> x;
    cin >> y;
    int x0 = 0, x1 = 0, y0 = 0, y1 = 0;
    int lenx = x.length();
    int leny = y.length();
    for0(i, lenx)
    {
        if (x[i] == '0')
        {
            x0++;
        }
        else
        {
            x1++;
        }
    }
    for0(i, leny)
    {
        if (y[i] == '0')
        {
            y0++;
        }
        else
        {
            y1++;
        }
    }
    if (x == y)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        if (x0 == y0 && x1 == y1)
        {
            if (areRotations(x, y))
            {
                int final = 1e6;
                int cnt = 0;
                string t = x;
                for (int i = 0; i < lenx; i++)
                {
                    leftrotate(t, 1);
                    cnt++;
                    if (t == y)
                    {
                        final = min(final, cnt);
                        break;
                    }
                }

                int cnt2 = 0;
                string t2 = y;
                for (int i = 0; i < leny; i++)
                {
                    rightrotate(t2, 1);
                    cnt2++;
                    if (t2 == y)
                    {
                        final = min(final, cnt2);
                        break;
                    }
                }

                if (final != 1e6)
                {
                    cout << final * k << endl;
                    return 0;
                }
            }
            cout << k * lenx / 2 << endl;
            return 0;
        }

        cout << -1 << endl;
    }

    return 0;
}
