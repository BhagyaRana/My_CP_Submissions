#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
typedef long long int ll;
typedef unsigned long long int ull;
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
    int n;
    cin >> n;
    mk(arr,n,ll);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    ull sum = 0ULL;
    ll cnt = 0LL;
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>sum)
        {
            sum += arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;   
    return 0;
}
