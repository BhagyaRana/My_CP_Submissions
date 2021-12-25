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

bool cmp(const pair<ll, ll>&i, const pair<ll, ll>&j) 
{ 
    double r1 = (double)i.second / i.first; 
    double r2 = (double)j.second / j.first; 
    return r1 > r2; 
} 

int main()
{
    b_v_r();

    ll n,m;
    cin >> n >> m; //Chocolates & Limit
    string chocname[n];
    char type[n];
    ll sweet[n];
    ll price[n];
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++)
    {
        cin >> chocname[i];
        cin >> type[i];
        cin >> sweet[i];
        cin >> price[i];
        if(type[i]=='S')
        {
            v.push_back(make_pair(sweet[i],price[i]));
        }
    }
   
    int new_n = v.size();
    // Aim : Maximise Price
    // O-1 KnapSack + Fractional KnapSack Combo
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < new_n; i++) 
    { 
        cout << v[i].first << "  " << v[i].second << " : " 
             << ((double)v[i].second / v[i].first) << endl; 
    } 

    // m = W
    // first -> sweet (weight)
    // Second -> price (value)

    ll curSweet = 0LL;  // Current weight in knapsack   
    ll ans = 0LL; // Result (value in Knapsack)
  
    int count = 1;
    for (int i = 0; i < new_n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curSweet + v[i].first <= m) 
        { 
            curSweet += v[i].first; 
            ans += v[i].second;
        } 
        // If we can't add current Item, add fractional part of it 
        else
        { 
            if(count>0&&(((v[i].first)/2) <= (m - curSweet)))
            {
                ans += (v[i].second); // check for odd 
                count--;
            }
        } 
    } 

    cout << ans << endl;
    
    return 0;
}
