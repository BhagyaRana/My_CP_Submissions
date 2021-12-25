#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

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
        int n,sum = 0;
        cin >> n;
        bool odd = false, even = false;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            sum += x;
            odd = odd | (x%2!=0);
            even = even | (x%2==0);
        }
        if(sum%2!=0 || (odd&&even))
            cout<<"YES"<<"\n";
        else
        {
            cout<<"NO"<<"\n";
        }  
    }
    return 0;
}
