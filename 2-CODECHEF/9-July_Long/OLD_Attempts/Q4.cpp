#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
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

    w(t)
    {
        ll n;
        cin >> n;

        ll xcor[n],ycor[n];

        ll xcordp = 0LL;
        ll xcordn = 0LL;
        ll ycordp = 0LL;
        ll ycordn = 0LL;

        for(ll i=0;i<(4*n)-1;i++)
        {
            cin >> xcor[i] >> ycor[i];
            if(xcor[i]>=0)
                xcordp ^= xcor[i];
            else
            {
                xcordn ^= abs(xcor[i]);
            }
            if(ycor[i]>=0)
                ycordp ^= ycor[i];
            else
            {
                ycordn ^= abs(ycor[i]);
            }
            
        }

        if(xcordp!=0)
        {
            cout << xcordp << " "; 
        }
        else
        {
            cout << "-" << xcordn << " ";
        }
        if(ycordp!=0)
        {
            cout << ycordp << endl; 
        }
        else
        {
            cout << "-" << ycordn << endl;
        }
        
    } 
    return 0;
}
