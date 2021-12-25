#include <bits/stdc++.h>
#include <ratio> // for ratio manipulation

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

int main()
{
    b_v_r();
    unsigned int n, m;
    cin >> n >> m;
    mk(arr, n, short int);
    // double den = 0.00000;
    int prod_den = 1;
    int prod_num = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        prod_den *= arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        prod_num += (prod_den/arr[i]);
    }

    cout << ((m*prod_den)/(prod_num)) << endl;

    return 0;
}
