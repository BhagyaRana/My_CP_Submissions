#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]

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
    int n,k;
    cin >> n >> k;
    mk(a,n,int);
    mk(s,n,int);
    mk(index,n,int);
    // mk(vis,n,bool);
    // bool vis[100000] = {false};
    int p = 0; 
    ll ans = 0LL;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }	
    
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        if(s[i]==0)
        {

            index[p] = i;
            p++;
            
        }
        else
        {
            ans += a[i];   
        }
        
    }
    ll gmax = -1;
    for(int i=0;i<p;i++)
    {
        int sum = 0;
        for(int j=index[i];j<(k+index[i])&&(j<n);j++)
        {
            if(s[j]!=1)
                sum += a[j];
        }
        // cout << "here" << endl;
        if(sum>gmax)
            gmax = sum;
        // cout<<gmax<<endl;
        // a[index[i]]
    }
    cout << (gmax + ans) << endl;
    
    return 0;
}
