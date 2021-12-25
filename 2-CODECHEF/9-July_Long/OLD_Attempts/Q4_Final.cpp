#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long int ll;


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

        set<ll> xcor; //Set for X Co-ordinate
        set<ll> ycor; //Set for Y Co-ordinate

        // Clearly the Answer is Co-ordinate whose freq is 1
        
        ll x,y;

        for(ll i=0;i<((4*n)-1);i++)
        {
            cin >> x >> y;

            if(xcor.count(x)==1)
            {
                xcor.erase(x);
            }
            else
            {
                xcor.insert(x);
            }

            if(ycor.count(y)==1)
            {
                ycor.erase(y);
            }
            else
            {
                ycor.insert(y);
            }
        }
        // Dereferencing to GET Answer

        cout << (*xcor.begin()) << " " << (*ycor.begin()) << endl;
    } 
    return 0;
}
