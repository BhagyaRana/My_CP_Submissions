#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
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

// All Variables Here
vector<int> a;
int m;
ll cnt;

// All Functions Here
ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

ll dfs(ll i, ll k)
{
    // Base Condition for DFS
    // I have Traverse whole Number
    if (i == m)
        return 1;

    ll ans = 0;

    for (ll idx = 0; idx <= 10; idx++)
    {
        if (idx * k < a[i])
            ans += power(cnt, m - 1 - i);
        else if (idx * k == a[i])
            ans += dfs(i + 1, k);
        else
            break;
        //cout<<idx*k<<" dp "<<ans<<endl;
    }

    return ans;
}

ll solve(ll n, ll k)
{

    if (k == 1)
        cnt = 10;
    else if (k == 2)
        cnt = 5;
    else if (k < 5)
        cnt = 10 / k + 1;
    else if (k >= 5)
        cnt = 2;

    a.clear();

    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }

    reverse(a.begin(), a.end());

    m = a.size();

    ll ans = 0;

    for (int i = 0; i <= 10; i++)
    {
        if (i * k < a[0])
            ans += power(cnt, m - 1); // 0 cant come in first place
        else if (i * k == a[0])
            ans += dfs(1, k); //a[0] work is done
        else
            break;

        // cout<<i*k<<" "<<ans<<endl;
    }

    return ans;
}

int main()
{
    b_v_r();

    ll l, r, k;

    w(t)
    {
        cin >> l >> r >> k;
        // watch2(solve(r, k), solve(l - 1, k));
        cout << solve(r, k) - solve(l - 1, k) << endl;
    }

    return 0;
}