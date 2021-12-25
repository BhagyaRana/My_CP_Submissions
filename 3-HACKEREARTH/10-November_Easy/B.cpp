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
int beauty(int n)
{
    int t = n;
    int sum = 0;
    while (t)
    {
        sum += t % 10;
        t /= 10;
    }
    if (sum < 10)
    {
        return sum;
    }
    else
    {
        return beauty(sum);
    }
}

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int b, k;
    cin >> b >> k;
    // b -> k
    int ans[10][10] = {0};

    ans[1][1] = 1;
    ans[1][2] = 19;
    ans[1][3] = 127;
    ans[1][4] = 1234;
    ans[1][5] = 12349;
    ans[1][6] = 123589;
    ans[1][7] = 1234567;
    ans[1][8] = 12345679;
    ans[1][9] = -1;

    ans[2][1] = 2;
    ans[2][2] = 29;
    ans[2][3] = 128;
    ans[2][4] = 1235;
    ans[2][5] = 12359;
    ans[2][6] = 123689;
    ans[2][7] = 1234568;
    ans[2][8] = 12345689;
    ans[2][9] = -1;

    ans[3][1] = 3;
    ans[3][2] = 12;
    ans[3][3] = 129;
    ans[3][4] = 1236;
    ans[3][5] = 12369;
    ans[3][6] = 123456;
    ans[3][7] = 1234569;
    ans[3][8] = 12345789;
    ans[3][9] = -1;

    ans[4][1] = 4;
    ans[4][2] = 13;
    ans[4][3] = 139;
    ans[4][4] = 1237;
    ans[4][5] = 12379;
    ans[4][6] = 123457;
    ans[4][7] = 1234579;
    ans[4][8] = 12346789;
    ans[4][9] = -1;

    ans[5][1] = 5;
    ans[5][2] = 14;
    ans[5][3] = 149;
    ans[5][4] = 1238;
    ans[5][5] = 12389;
    ans[5][6] = 123458;
    ans[5][7] = 1234589;
    ans[5][8] = 12356789;
    ans[5][9] = -1;

    ans[6][1] = 6;
    ans[6][2] = 15;
    ans[6][3] = 123;
    ans[6][4] = 1239;
    ans[6][5] = 12345;
    ans[6][6] = 123459;
    ans[6][7] = 1234689;
    ans[6][8] = 12456789;
    ans[6][9] = -1;

    ans[7][1] = 7;
    ans[7][2] = 16;
    ans[7][3] = 124;
    ans[7][4] = 1249;
    ans[7][5] = 12346;
    ans[7][6] = 123469;
    ans[7][7] = 1234789;
    ans[7][8] = 13456789;
    ans[7][9] = -1;

    ans[8][1] = 8;
    ans[8][2] = 17;
    ans[8][3] = 125;
    ans[8][4] = 1259;
    ans[8][5] = 12347;
    ans[8][6] = 123479;
    ans[8][7] = 1235789;
    ans[8][8] = 23456789;
    ans[8][9] = -1;

    ans[9][1] = 9;
    ans[9][2] = 18;
    ans[9][3] = 126;
    ans[9][4] = 1269;
    ans[9][5] = 12348;
    ans[9][6] = 123489;
    ans[9][7] = 1236789;
    ans[9][8] = 12345678;
    ans[9][9] = 123456789;

    cout << ans[b][k] << endl;

    return 0;
}
