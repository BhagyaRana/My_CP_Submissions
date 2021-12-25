#pragma GCC optimize("O2") 

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
    w(t)
    {
        int n,b,m;
        cin >> n >> b >> m;
        
        // n-1 integers 
        // 1--> b-1
        // b --> 2b-1
        // 3b --> 4b-1
        // x(b) + y = query
        int start = 0;
        int end = n-1;
        int ans = 1;
        int query,num;

        for(int i=0;i<m;i++)
        {
            cin >> query;
            if(!(query>=start&&query<=end))
            {
                ans++;
            }
            
            num = query/b;
            start = num*b;
            end = (num+1)*b - 1;
        }
        cout << ans << endl;

    }
        
    return 0;
}
