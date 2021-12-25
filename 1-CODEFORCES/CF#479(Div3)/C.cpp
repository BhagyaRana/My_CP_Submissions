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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

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

int main()
{
    b_v_r();

    int n, k, i;

    cin >> n >> k;

    ll a[n] ={ 0 };

    for (i=0;i<n;i++)
    {
        cin >> a[i];
    }

    // 1 3 3 5 7 10 20 

    sort(a, a+n);
    
    ll ans = 0;

    if(k==0)
    {
        ans = a[0] - 1;
    }
    else
    {
        ans = a[k-1];
    }
    
    ll cnt = 0;
    for(i=0;i<n;i++)
    {
        if(a[i]<=ans)
            cnt++;
    }

    if(ans<1 || (cnt!=k))
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    
    return 0;
}
