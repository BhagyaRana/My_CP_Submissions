#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
#define MOD 998244353
#define INF 1e18
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pll pair<long long, long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define T        \
    ll test;     \
    cin >> test; \
    while (test--)
#define rep(i, a, n) for (ll i = a; i < (long long)n; ++i)
#define repr(i, n, a) for (ll i = n; i > (long long)a; --i)
#define MAX 100005
typedef long long ll;
typedef long double ld;
using namespace std;

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


ll res = 3;

void funct(ll a[], ll p[], ll ans, ll ln)
{
    // cout << a[0] << " " << p[0] << endl;
    if (ln == 1)
    {
        if (a[0] != p[0])
            ans += 1;
        res = min(res, ans);
        // cout << res << endl;
        return;
    }
    if (a[0] == p[0])
    {
        // cout << a[0] << "==" << p[0] << std::endl;
        ll temp1[ln], temp2[ln];
        rep(i, 0, ln)
        {
            temp1[i] = a[i];
            temp2[i] = p[i];
        }
        if (ln > 1)
            funct(temp1 + 1, temp2 + 1, ans, ln - 1);
        return;
    }
    if ((a[0] != 0) && ((a[0] + p[0]) % a[0]) == 0)
    {
        ll temp1[ln], temp2[ln];
        rep(i, 0, ln)
        {
            temp1[i] = a[i];
            temp2[i] = p[i];
        }
        ll dv = p[0] / a[0];
        temp1[0] = a[0] * dv;
        if (ln == 3)
        {
            temp1[0] = a[0] * dv;
            temp1[1] = a[1];
            temp1[2] = a[2];

            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
            temp1[0] = a[0] * dv;
            temp1[1] = a[1] * dv;
            temp1[2] = a[2];

            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
            temp1[0] = a[0] * dv;
            temp1[1] = a[1];
            temp1[2] = a[2] * dv;

            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
            temp1[1] = a[1] * dv;
            temp1[2] = a[2] * dv;
            temp1[0] = a[0] * dv;

            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
        }
        if (ln == 2)
        {
            temp1[0] = a[0] * dv;
            temp1[1] = a[1];

            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
            temp1[0] = a[0] * dv;
            temp1[1] = a[1] * dv;
            funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
        }
    }
    ll temp1[ln], temp2[ln];
    rep(i, 0, ln)
    {
        temp1[i] = a[i];
        temp2[i] = p[i];
    }
    ll diff = p[0] - a[0]; // cout << diff << endl;
    temp1[0] = a[0] + diff;
    if (ln == 3)
    {
        temp1[0] = a[0] + diff;
        temp1[1] = a[1];
        temp1[2] = a[2];
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);

        temp1[1] = a[1] + diff;
        temp1[0] = a[0] + diff;
        temp1[2] = a[2];
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);

        temp1[0] = a[0] + diff;
        temp1[1] = a[1];
        temp1[2] = a[2] + diff;
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);

        temp1[0] = a[0] + diff;
        temp1[1] = a[1] + diff;
        temp1[2] = a[2] + diff;
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
    }
    if (ln == 2)
    {
        temp1[0] = a[0] + diff;
        temp1[1] = a[1];
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
        temp1[1] = a[1] + diff;
        temp1[0] = a[0] + diff;
        funct(temp1 + 1, temp2 + 1, ans + 1, ln - 1);
    }
    return;
}


void solve()
{
    res = 3;
    ll a, b, c, p, q, r;

    cin >> a >> b >> c;
    cin >> p >> q >> r;

    ll area;
    ll slo = 0;
    ll distn1 = abs(a - p);
    ll distn2 = abs(b - q);
    ll dist3 = abs(r - p);

    if ((b - a) != 0 && (q - p) % (b - a) == 0)
        slo = 1;
    if ((c - a) != 0 && (r - p) % (c - a) == 0)
        slo = 1;
    if ((b - c) != 0 && (q - r) % (b - c) == 0)
        slo = 1;
    
    ll f = 0;
    ll ma = 1;
    ll del = 0;

    if (p == q || q == r || r == p)
        ma = 0;
    
    area = a * (q - r) + b * (r - p) + c * (p - q);

    if (area == 0 && slo == 1)
    {
        res = 2;
        // cout << "yes\n";
    }

    if (a != b && p - ((q - p) / (b - a)) * a + c == r && (q - p) % (b - a) == 0)
        del = 1;
    if (c != b && r - ((q - r) / (b - c)) * c + a == p && (q - r) % (b - c) == 0)
        del = 1;
    if (a != c && p - ((r - p) / (c - a)) * a + b == q && (r - p) % (c - a) == 0)
        del = 1;

    if (del == 1)
        res = 2;
        
    ll x[3], y[3];

    x[0] = a;
    y[0] = p;
    x[1] = c;
    y[1] = r;
    x[2] = b;
    y[2] = q;
    // cout << "one\n";

    funct(x, y, 0, 3);

    x[0] = a;
    y[0] = p;
    x[1] = b;
    y[1] = q;
    x[2] = c;
    y[2] = r;
    // cout << "one\n";
    funct(x, y, 0, 3);

    x[0] = b;
    y[0] = q;
    x[1] = a;
    y[1] = p;
    x[2] = c;
    y[2] = r;
    // cout << "one\n";

    funct(x, y, 0, 3);
    x[0] = b;
    y[0] = q;
    x[1] = c;
    y[1] = r;
    x[2] = a;
    y[2] = p;
    // cout << "one\n";

    funct(x, y, 0, 3);

    x[0] = c;
    y[0] = r;
    x[1] = b;
    y[1] = q;
    x[2] = a;
    y[2] = p;
    // cout << "one\n";
    funct(x, y, 0, 3);
    x[0] = c;
    y[0] = r;
    x[1] = a;
    y[1] = p;
    x[2] = b;
    y[2] = q;
    // cout << "one\n";

    funct(x, y, 0, 3);

    cout << res << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    rep(alpha, 0, tc)
    {
        solve();
    }
    return 0;
}