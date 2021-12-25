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
    int k;
    w(t)
    {
        cin >> k;
        char arr[9][9];
        memset(arr,'.',sizeof(arr));
        arr[1][1] = 'O';
        if(k<=8)
        {
            // Make 2nd Row Blocked
            for(int j=1;j<=8;j++)
            {
                arr[2][j] = 'X'; 
            }
            // k = 1 -> 7 'X'
            // k = 2 -> 6 'X'
            // arr[1][8] -> 8 - k
            int cnt = 8 - k;
            int last = 8;
            for(int i=0;i<cnt;i++)
            {
                arr[1][last] = 'X';
                last--;
            }
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=8;j++)
                {
                    cout << arr[i][j] ;
                }
                cout << endl;
            }
            cout << endl;
        }
        else
        {
            // k > 8
            int cnt = k - 8;
            for(int i=2;i<=8;i++)
            {
                for(int j=1;j<=8;j++)
                {
                    if(cnt>0)
                    {
                        cnt--;
                    }
                    else
                    {
                        arr[i][j] = 'X';
                    }
                    
                }
            }
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=8;j++)
                {
                    cout << arr[i][j] ;
                }
                cout << endl;
            }
            cout << endl;
        }
        
    }
        
    return 0;
}
