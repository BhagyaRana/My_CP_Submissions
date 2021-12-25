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
typedef unsigned long long ull;
#define mk(arr, n, type) type *arr = new type[n]

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

ll highestPowerOf2(ll n) 
{ 
    ll cnt = 0LL;  
    while(n)
    {
        n = n>>1;
        cnt++;
    }
    return cnt-1;
} 

bool compare(bitset<60> b,short int vis[])
{
    for(int i=0;i<60;i++)
    {
        if(!(vis[i]>=b[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    b_v_r();
    ull pow2[60];
    // ull sum = 1;
    pow2[0] = 1;
    for (int i = 1; i < 60; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        // sum += pow2[i];
    }
    // cout << "Sum : " << sum << endl;

    w(t)
    {
        ll n;  // Hunger Requirement
        int m; // No of Elements in Array

        cin >> n >> m;
        ll k = n;

        bitset<60> b(n);
        cout << "Bitset : "<<b << endl;

        mk(arr, m, ll);

        // vector<pair<ll,ll>> v;
        mk(vis, 60, short int);
        // memset(vis,0,sizeof(vis));
        for(int i=0;i<60;i++)
        {
            vis[i] = 0;
        }

        ull sum = 0;
        
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            vis[highestPowerOf2(arr[i])]++;
            sum += arr[i];
        }
        // cout << "Visited : ";
        // for(int i=59;i>=0;i--)
        // {
        //     cout<<vis[i];
        // }
        // cout << endl;

        if (sum < n)
        {
            cout << "-1" << endl;
        }
        // else
        // {
        //     if (sum == n)
        //     {
        //         cout << "0" << endl;
        //     }
        //     else
        //     {
        //         // sum > n
        //         ll cuts = 0LL;
                
        //     }
        // }

        
            for(int i=59;i>=0;i--)
            {
                if(vis[i]==0&&b[i]==0)
                    continue;
                if(vis[i]>=b[i]&&(b[i]!=0))
                {
                    b[i] = 0;
                    vis[i]--;
                }
            }

           
        ll cuts = 0LL;
        
        while(!(b.count()==0))
        {
            cuts++;

             

        }
        
        cout << "Bitset  : "<< b << endl;
        cout << "Visited : ";
        for(int i=59;i>=0;i--)
        {
            cout<<vis[i];
        }
        cout << endl;

    }

    return 0;
}
