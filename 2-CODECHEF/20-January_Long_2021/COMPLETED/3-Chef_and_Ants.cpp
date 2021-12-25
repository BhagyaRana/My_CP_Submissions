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
#define sz(a) (ll)((a).size())
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
// Number Of Lines
ll N;
// Number of Ants in Each Lines
ll M;
// Frequency of All Values [Absolute]
map<ll, ll> freq;

// Temp Variables
ll pos, col, ele;
// All Functions Here
void solve()
{
    cin >> N;
    freq.clear();
    // To Store all Ants on Different Lines
    vector<ll> line[N];
    for0(i, N)
    {
        // Size of Line "i+1"
        cin >> M;
        for0(j, M)
        {
            cin >> pos;
            // Store the Ant's Position
            line[i].pb(pos);
            // Increase the Frequency of that Position
            freq[abs(pos)]++;
        }
    }
    // INPUT TAKEN
    // Number of Collisions
    ll ans = 0;
    // Step 1 : Sort All Lines [Incase Input Given was Not Sorted]
    for0(i, N)
    {
        sort(all(line[i]));
    }
    // Step 2 : All those Elements Whose Freq>1 will Collide atleast 1 time [Observation]
    for (auto f : freq)
    {
        if ((f.second) > 1)
        {
            ans++;
        }
    }
    // watch(ans);
    // Step 3 : For Each Element in Each Line Add the Collisions it will Have
    for0(i, N)
    {
        for0(j, sz(line[i]))
        {
            // line[i][j] <- Current Element [Element on Line "i+1" & position "j+1"]
            ele = line[i][j];
            // Number of Collison it will have
            col = 0;
            // CASE 1 : If Freq of ele > 1
            if (freq[abs(ele)] > 1)
            {
                // If ele is Positive
                if (ele > 0)
                {
                    // It will Collide with All Remaining ELement in its Line [After it i.e. Right Side]
                    col += ((sz(line[i])) - (j + 1));
                }
                else
                {
                    // It will Collide with All Remaining ELement in its Line [Before it i.e. Left Side]
                    col += (j);
                }
            }
            // CASE 2 : fre of ele = 1
            else
            {
                // If ele is Positive
                if (ele > 0)
                {
                    // Find the Negative Counter Part of that Element
                    // It will Collide with All Remaining ELement in its Line [After it(-ve CP) i.e. Left Side]
                    auto it = lower_bound(all(line[i]), (-1 * ele));
                    col += (ll)(it - line[i].begin());
                }
                else
                {
                    // Find the Positive Counter Part of that Element
                    // It will Collide with All Remaining ELement in its Line [After it(+ve CP) i.e. Right Side]
                    auto it = upper_bound(all(line[i]), (-1 * ele));
                    col += (ll)((ll)sz(line[i]) - (ll)(it - line[i].begin()));
                }
            }
            // watch(col);
            // Add the Number of Collision Contribution to Main Answer
            ans += col;
        }
    }
    // Step 4 : Print the Number of Collisiions
    cout << ans << endl;

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
