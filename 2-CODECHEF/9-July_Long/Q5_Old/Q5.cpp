#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef long long int ll;
typedef unsigned long long int ull;

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// void showpq(priority_queue <ll, vector<ll>, greater<ll>> gq) 
// { 
//     cout << "Priority Queue : " << endl;

//     priority_queue <ll, vector<ll>, greater<ll>> g = gq; 
//     while (!g.empty()) 
//     { 
//         cout << '\t' << g.top(); 
//         g.pop(); 
//     } 
//     cout << '\n'; 
// } 


int main()
{
    b_v_r();
    ll n;
    w(t)
    {
        cin >> n;

        priority_queue <ll, vector<ll>, greater<ll>> pqA;
        priority_queue <ll, vector<ll>, greater<ll>> pqB;


        ll a,b;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            pqA.push(a);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b;
            pqB.push(b);
        }

        ll cost = 0LL;
        ll a1,b1;

        int flag = 1;

        // showpq(pqA); 
        // showpq(pqB);
        vector<ll> temp;

        while((!(pqA.empty()))&&(!(pqB.empty())))
        {
            if(pqA.top()==pqB.top())
            {
                temp.push_back(pqA.top());
                pqA.pop();
                pqB.pop();
            }
            else
            {
                a1 = pqA.top();
                b1 = pqB.top();

                pqA.pop();
                pqB.pop();
                
                pqA.push(b1);
                pqB.push(a1);

                if(temp.size()==0)
                    cost += min(a1,b1);
                else
                {
                    if((2*temp[0])<min(a1,b1))
                    {
                        cost += temp[0];
                        cost += temp[0];
                    }
                    else
                    {
                        cost += min(a1,b1);
                    }
                }
                
                if(pqA.top()!=pqB.top())
                {
                    // cout << "-1" << endl;
                    flag = 0;
                    break;
                }
                else
                {
                    pqA.pop();
                    pqB.pop();
                }
                
            }
        }
        
        if(flag)
            cout << cost << endl;
        else
            cout << "-1" << endl;

    }

    return 0;
}
