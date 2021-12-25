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

int main()
{
    b_v_r();
    w(t)
    {
        string str;
        // cin.ignore(1, '\n');
        cin >> str;
        char dl = '/';
        int n = str.size();
        vector <int> index;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='/')
            {
                // if(str[i+1]!='/'&&i+1<n)
                    index.push_back(i);
                // if(str[i-1]=='/')

        
            }

        }
        int m = index.size();
        for(int i=1;i<m;i++)
        {
            // index[i]
            if(index[i]-index[i-1]>1)
                {
                    string sub = str.substr(index[i]+1,index[i]);
                    cout << sub << endl;
                }

        }
        // for(vector <int> ::iterator it = index.begin();it!=index.end();it++)
        // {
        //     // int k = *(++it);
    
        //     cout << *it << " " ;

        // }
        // cout << endl;


        // size_t pos = str.find("//");
        // string sub = str.substr(pos);   
        // cout << sub << endl;
    }
        
    return 0;
}
