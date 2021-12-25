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
    // DONT FORGET TO COMMENT THIS -> IT CAUSES SIGABORT IN CODECHEF
    // b_v_r();
    w(t)
    {
        // Size of Array of Candies
        ll n;
        cin >> n;

        ll a[n + 1] = {0};

        for1(i, n)
        {
            cin >> a[i];
        }

        //Total Number Of Queries
        ll query;
        cin >> query;

        // Number of Turns
        ll r;

        // Final Answer After Each Query
        ll chef_candies = 0;
        ll chefu_candies = 0;

        // Intially -> Open for Chef || Closed
        bool counter_window = true;

        ll offer = 0;
        ll idx = 0;

        unordered_map<int, int> ans;

        r = 100;
        for (int turn = 1; turn <= r; turn++)
        {
            // He is Offered
            idx = ((turn - 1 + n) % n) + 1;
            offer = a[idx];

            // 1 <= M <= offer
            // G1 -> Since Chef Wants to Maximize His Own Candies
            // G2 -> Minimize his Opponent Candies
            // If it is nth Turn, n+1 th turn
            // Counter -> 1 0 -> 0 1
            if (turn % n == 0)
            {
                // He Should Try to Make his Sum Odd
                if (offer != 1)
                {
                    if ((chef_candies + offer) % 2 == 0)
                    {
                        chef_candies = ((chef_candies) % mod + (offer - 1 + mod) % mod) % mod;
                    }
                    else
                    {
                        chef_candies = ((chef_candies) % mod + (offer) % mod) % mod;
                    }
                }
                else
                {
                    // He is Offered with No Choice but Accept 1 Candy
                    // From Next Turn Window will be Changed
                    if ((chef_candies + offer) % 2 == 0)
                    {
                        chef_candies = ((chef_candies) % mod + (offer) % mod) % mod;
                        for (int k = turn + 1; k <= r; k++)
                        {
                            ll offer2 = a[(k - 1) % n + 1];
                            if (offer2 != 1)
                            {
                                chefu_candies = ((chefu_candies) % mod + (offer2) % mod) % mod;
                            }
                            else
                            {
                                if ((chefu_candies + offer2) % 2 == 0)
                                {
                                    // Now Chef Will Get Chance
                                    chefu_candies = ((chefu_candies) % mod + (offer2) % mod) % mod;
                                    turn = k;
                                    // turn will be incremented later
                                    break;
                                }
                                else
                                {
                                    chefu_candies = ((chefu_candies) % mod + (offer2) % mod) % mod;
                                }
                            }
                        }
                    }
                    else
                    {
                        chef_candies = ((chef_candies) % mod + (offer) % mod) % mod;
                    }
                }
            }
            else
            {
                
                chef_candies = ((chef_candies) % mod + (offer) % mod) % mod;
            }
            // watch(turn);
            // watch2(chef_candies, chefu_candies);
            ans[turn] = chef_candies;
        }

        while (query--)
        {
            cin >> r;
            cout << ans[r] << endl;
        }
    }

    return 0;
}
