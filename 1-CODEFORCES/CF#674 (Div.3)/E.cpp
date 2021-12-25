#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  int x;cin >> x;while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here



// All Variables Here


int main()
{
    b_v_r();
    ll n;
    cin >> n;
    ll stone_A, paper_A, sci_A;
    ll stone_B, paper_B, sci_B;
    ll stone_A2, paper_A2, sci_A2;
    ll stone_B2, paper_B2, sci_B2;
    cin >> stone_A >> sci_A >> paper_A;
    cin >> stone_B >> sci_B >> paper_B;
    
    stone_A2 = stone_A;
    paper_A2 = paper_A;
    sci_A2 = sci_A;

    stone_B2 = stone_B;
    paper_B2 = paper_B;
    sci_B2 = sci_B;

    ll min_rnd = 0;
    ll max_rnd = 0;
    // Stone Vs Scissor
    ll t1 = min(stone_A, sci_B);
    max_rnd += t1;
    stone_A -= t1;
    sci_B -= t1;

    // Paper Vs Stone
    ll t2 = min(paper_A, stone_B);
    max_rnd += t2;
    paper_A -= t2;
    stone_B -= t2;

    // Scissor Vs Paper
    ll t3 = min(sci_A, paper_B);
    max_rnd += t3;
    sci_A -= t3;
    paper_B -= t3;

    // // Stone Vs Scissor
    // t1 = min(stone_B2, sci_A2);
    // min_rnd += t1;
    // stone_B2 -= t1;
    // sci_A2 -= t1;

    // // Paper Vs Stone
    // t2 = min(paper_B2, stone_A2);
    // min_rnd += t2;
    // paper_B2 -= t2;
    // stone_A2 -= t2;

    // // Scissor Vs Paper
    // t3 = min(sci_B2, paper_A2);
    // min_rnd += t3;
    // sci_B2 -= t3;
    // paper_A2 -= t3;

    // min_rnd += min(stone_A2,stone_B2);
    // min_rnd += min(paper_A2,paper_B2);
    // min_rnd += min(sci_A2,sci_B2);

    // min_rnd = n - min_rnd;

    stone_A2 -= min(stone_A2,paper_B2);
    stone_A2 -= min(stone_A2,stone_B2);
    min_rnd += stone_A2;

    paper_A2 -= min(paper_A2,paper_B2);
    paper_A2 -= min(paper_A2,sci_B2);
    min_rnd += paper_A2;

    sci_A2 -= min(sci_A2,sci_B2);
    sci_A2 -= min(sci_A2,stone_B2);
    min_rnd += sci_A2;

    cout << min_rnd << " " << max_rnd << endl;

    return 0;
}