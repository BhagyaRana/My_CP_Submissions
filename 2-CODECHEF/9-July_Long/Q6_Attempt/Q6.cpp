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
        ll n,x;
        cin >> n >> x; // n -> No of Countries Intial Cures -> x

        ll a[n];
        ll day = 0LL;
        ll cures_avail = x;
        ll cures_used = 0LL;
        ll min_days = 0LL;
        //  One Country Per Day ONLY
        // Cures used < population of country
        
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }

        sort(a,a+n);

        // a[1] <= x -> a[1] -= x; (used = x;day++;x=(2*used))
        ll ub_ind = 0LL;
        bool flag = true;
        while(x<1000000001 && flag)
        {
            ub_ind = upper_bound(arr,arr+n,x/2) - arr;

            if(a[ub_ind]>x)
            {
                x *= 2;
                day++;
            }
            else
            {
                x = a[ub_ind]*2;
                a[ub_ind] = 0;
                day++;
                
                flag = false;
                for(ll i=0;i<n;i++)
                {
                    if(a[i]!=0)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            
        }





        for(int i=1;i<=n;i++)
        {
            
            if(a[i]<=cures_avail)
            {
                day++;
                cures_used = a[i];
                a[i] = 0;
                cures_avail = (2*cures_used);
                // cout << "Day : " << day << endl;
                // cout << "Cures Avail : " << cures_avail << endl;
                // cout << "Cures Used :" << cures_used << endl;
                // cout << "a[" << i << "] = " << a[i] << endl;
            }
            else
            {
                // a[i] > cures_avail
                while(a[i]>0)
                {
                    day++;
                    a[i] -= cures_avail;
                    cures_used = cures_avail;
                    cures_avail = (2*cures_used);
                    if(a[i]<=cures_avail)
                    {
                        day++;
                        cures_used = a[i];
                        a[i] = 0;
                        cures_avail = (2*cures_used);
                        break;
                    }
                }
            }

            for(int j=i+1;j<=n;j++)
            {
                a[j] *= 2;
            }
            
        }

        cout << day << endl;

    }
    
        
    return 0;
}
