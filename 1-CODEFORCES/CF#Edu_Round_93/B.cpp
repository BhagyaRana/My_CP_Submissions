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
    
    w(t)
    {
        string s;
        cin >> s;
        int len = s.length();
        vector<int> v;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='1')
            {
                int cnt = 0;
                int idx = i;
                while((idx<len)&&s[idx]=='1')
                {
                    cnt++;
                    idx++;
                }
                i = idx-1;
                v.emplace_back(cnt);
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        // cout << "VECTOR" << endl;
        // for(auto ele : v)
        // {
        //     cout << ele << endl;
        // }
        int ascore = 0;
        int sz = v.size();
        for(int i=0;i<sz;i++)
        {
            if(i%2==0)
            {
                ascore += v[i];
            }
        }
        cout << ascore << endl;
    }

    return 0;
}
