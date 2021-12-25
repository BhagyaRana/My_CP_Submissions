#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;

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

// All Functions Here

bool pow2(ll num)
{
    return (!(num & (num - 1)));
}

// All Variables Here

int main()
{
    b_v_r();
    // Precomputed Answer
    vector<int> ans(1e5+2);
    for(int j=0;j<=1e5+1;j++)
    {
        ans[j] = j;
    }
    int p2 = 2,tmp;
    for(;p2<=1e5+1;p2*=2)
    {
        tmp = ans[p2];
        ans[p2] = ans[p2+1];
        ans[p2+1] = tmp;
    }

    ans[1] = 2;
    ans[2] = 3;
    ans[3] = 1;

    ll t,n,i;
    cin >> t;
    while(t--)
    {
        cin >> n;

        //Smaller Edge Case
        if(n==1)
        {
            cout << 1 << endl;
            continue;
        }

        if(pow2(n))
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            i=1;
            for(;i<=n;i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            continue;
        }
    }

    return 0;
}