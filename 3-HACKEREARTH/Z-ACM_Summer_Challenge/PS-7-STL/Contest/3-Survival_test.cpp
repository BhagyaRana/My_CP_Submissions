#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
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

void showpq(priority_queue <ll> gq) 
{ 
    priority_queue <ll> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 

int main()
{
    b_v_r();
    w(q)
    {
        int n;
        cin >> n;
        ll si;
        priority_queue<ll> pq;
        for(int i=0;i<n;i++)
        {
            cin >> si;
            pq.push(si);
        }
        // showpq(pq);
        while(pq.size()>=2)
        {
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            if(t1>t2)
            {
                pq.emplace(t1-t2);
            }
            else
            {
                if(t2>t1)
                {
                    pq.emplace(t2-t1);
                }
            } 
        }
        // showpq(pq);
        if(pq.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << pq.top() << endl;
        }
        


    }
        
    return 0;
}
