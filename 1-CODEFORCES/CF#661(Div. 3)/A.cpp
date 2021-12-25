#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();
    int n,i,x;
    w(t)
    {
        cin >> n;
        int a[n];
        set<int> s;
        for(i=0;i<n;i++)
        {
            cin >> x;
            s.insert(x);
        }
        int sz = s.size();
        if(sz == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            bool flag = true;
            int old;
            for(auto it = s.begin();it!=s.end();it++)
            {
                if(it == s.begin())
                {
                    old = *it;
                }
                if((*it - old) >=2)
                {
                    flag = false;
                    break;
                }
                old = *it;
            }
            if(flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
        }
        
    }

    return 0;
}
