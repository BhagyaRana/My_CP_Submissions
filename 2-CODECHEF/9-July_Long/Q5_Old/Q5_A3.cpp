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
    ll n;
    w(t)
    {
        cin >> n;

        map<ll,ll> mpA;
        map<ll,ll> mpB;

        set<ll> se;

        ll a,b;

        for(int i=0;i<n;i++)
        {
            cin >> a;
            se.insert(a);
            auto it = mpA.find(a);
            if(it==mpA.end())
            {
                mpA[a] = 1;
            }
            else
            {
                mpA[a] += 1;
            }
        }

        for(int i=0;i<n;i++)
        {
            cin >> b;
            se.insert(b);
            auto it = mpB.find(a);
            if(it==mpB.end())
            {
                mpB[b] = 1;
            }
            else
            {
                mpB[b] += 1;
            }
        }

        ll cost = 0LL,swap = 0LL;
        auto it = se.begin();
        ll tempmin = *it;

        for(auto it=se.begin();it!=se.end();it++)
        {
            // se[i]
            auto it1 = mpA.find(*it);
            auto it2 = mpB.find(*it);
            if(it1==mpA.end())
            {
                mpA[*it] = 0;
            }
            if(it2==mpB.end())
            {
                mpB[*it] = 0;
            }

            if(mpA[*it]==mpB[*it])
            {
                continue;
            }
            else
            {
                if(mpA[*it]>mpB[*it])
                {
                    bool check = true;
                    while(check)
                    {
                        mpA[*it]--;
                        mpB[*it]++;
                        swap++;
                        cost += tempmin; 
                        // cost
                        if(mpA[*it]==mpB[*it])
                            check = false;
                    }

                }
                else
                {
                    if(mpA[*it]<mpB[*it])
                    {
                        bool check = true;
                        while(check)
                        {
                            mpB[*it]--;
                            mpA[*it]++;
                            swap++;
                            cost += tempmin;
                            // cost
                            if(mpA[*it]==mpB[*it])
                                check = false;
                        }
                    }
                    
                }
                
            }
            
        }

        cout << cost << endl;



    }

        
    return 0;
}
