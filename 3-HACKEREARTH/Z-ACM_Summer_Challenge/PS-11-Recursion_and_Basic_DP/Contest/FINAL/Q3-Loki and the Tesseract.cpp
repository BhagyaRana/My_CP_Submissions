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
    
    int n,m;
    cin >> n >> m;
    bool mat[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    int arr[n][m];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                arr[i][j] = 0;
            }
            else
            {
                // Check to Top and Left Of Element
                if(i-1>=0&&j-1>=0)
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]) + 1;
                else
                {
                    arr[i][j] = 1;
                }
                
            }
        }
    }
    int max = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]>max)
                max = arr[i][j];
        }
    }
    cout << max << endl;

    return 0;
}
