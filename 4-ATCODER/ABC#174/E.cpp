#pragma GCC optimize("O2")

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


bool check(int x, int k, const vector<int> &a)
{
    int64_t res = 0;
    
    for (auto i : a)
    {
        res += (i - 1) / x;
    }

    return res <= k;
}

int main()
{
    b_v_r();

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin >> a[i];
    
    int l = 1, r = 1e9, ans = 0;
    // Binary Search  
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, k, a))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}