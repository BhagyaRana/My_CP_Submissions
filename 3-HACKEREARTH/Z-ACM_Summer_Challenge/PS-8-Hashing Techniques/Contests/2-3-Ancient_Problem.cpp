#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();

    int n, q;
    cin >> n >> q;

    map<int, vector<int>> m;

    vector<int>::iterator itr1, itr2;

    mk(arr, n, int);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]].push_back(i + 1);
    }

    while (q--)
    {
        int d,k,l,r;
        cin >> d >> k >> l >> r;

        itr1 = lower_bound(m[d].begin(), m[d].end(), l);
        itr2 = upper_bound(m[d].begin(), m[d].end(), r);
        
        if ((itr2 - itr1) >= k)
        {
            advance(itr1, k - 1); // move itr1 by k-1 places
            cout << *(itr1) << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}
