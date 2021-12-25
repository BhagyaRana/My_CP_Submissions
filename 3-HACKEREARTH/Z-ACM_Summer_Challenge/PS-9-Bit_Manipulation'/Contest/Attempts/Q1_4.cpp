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
        ll n;
        int m;
        cin >> n >> m;
        bitset<60> hunger(n);
        bitset<60> ans;
        

        // bitset<60> num[m];
        ll x;
        ll sum = 0LL;
        for(int i=0;i<m;i++)
        {
            cin >> x;
            sum += x;
            bitset<60> num(x);
            ans |= num;
        }
        if(sum < n)
        {
            cout << "-1" << endl;
        }
        if(sum == n)
        {
            cout << "0" << endl;
        }
        else
        {
            //sum > n
            for(int i=0;i<60;i++)
            {
                if(ans[i]==hunger[i]&&((ans[i]!=0)&&(hunger[i]!=0)))
                {
                    ans[i] = 0;
                    hunger[i] = 0;
                }
            }
        }
        

    }
        
    return 0;
}
