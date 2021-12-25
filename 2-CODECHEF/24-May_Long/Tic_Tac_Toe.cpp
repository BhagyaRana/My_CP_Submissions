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
string s[3];

// All Functions Here

// Is Win?
bool possible(char letter);

void solve()
{
    F0R(i, 3)
    cin >> s[i];

    int cntX = 0, cntO = 0, spaces = 0;
    F0R(i, 3)
    {
        F0R(j, 3)
        {
            if (s[i][j] == 'X')
                cntX++;
            else if (s[i][j] == 'O')
                cntO++;
            else
                spaces++;
        }
    }

    // 3: if the position is not reachable.
    // Mathematically 0<=cntX<=5 && 0<=cntO<=4 && cnt0<=cntX
    // 3.1 = Limits on cntX & cntO
    if ((cntX > cntO + 1) || (cntO > cntX))
    {
        cout << "3\n";
        return;
    }

    bool possXwin = possible('X');
    bool possOwin = possible('O');

    // 3.2 = Both can't Win Simultanously
    // 3.3 = O won, then cntX and cntO must be Same
    // 3.3 = X won, then cntX must be cnt0+1
    if ((possXwin && possOwin) || (possOwin && cntX > cntO) || (possXwin && cntX == cntO))
    {
        cout << "3\n";
        return;
    }

    // 1: if the position is reachable, and the game has drawn or one of the players won.
    // 1.1 = Either One of Players has Already Won
    // 1.2 = All Cells Filled
    if ((possXwin || possOwin) || (cntX + cntO == 9))
    {
        cout << "1\n";
        return;
    }

    // ALL REMIANING CASES
    // 2: if the position is reachable, and the game will continue for at least one more move.
    cout << "2\n";
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

// Is Win?
bool possible(char letter)
{
    // Horizontal Row 1
    if ((s[0][0] == letter) && (s[0][0] == s[0][1]) && (s[0][1] == s[0][2]))
        return true;
    // Horizontal Row 2
    if ((s[1][0] == letter) && (s[1][0] == s[1][1]) && (s[1][1] == s[1][2]))
        return true;
    // Horizontal Row 3
    if ((s[2][0] == letter) && (s[2][0] == s[2][1]) && (s[2][1] == s[2][2]))
        return true;

    // Vertical Column 1
    if ((s[0][0] == letter) && (s[0][0] == s[1][0]) && (s[1][0] == s[2][0]))
        return true;
    // Vertical Column 2
    if ((s[0][1] == letter) && (s[0][1] == s[1][1]) && (s[1][1] == s[2][1]))
        return true;
    // Vertical Column 3
    if ((s[0][2] == letter) && (s[0][2] == s[1][2]) && (s[1][2] == s[2][2]))
        return true;

    // Principal Diagonal
    if ((s[0][0] == letter) && (s[0][0] == s[1][1]) && (s[1][1] == s[2][2]))
        return true;
    // Non-Principal Diagonal
    if ((s[0][2] == letter) && (s[0][2] == s[1][1]) && (s[1][1] == s[2][0]))
        return true;

    return false;
}
