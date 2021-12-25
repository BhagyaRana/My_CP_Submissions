#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl    '\n'
#define mk(arr,n,type)   type *arr=new type[n]
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, count = 0;
        cin >> n >> k;
        int lower = k / (n - 1);
        int pos = k - (lower * (n - 1));
        for (int i = (n * lower); i < (n + 1)*lower; i++)
        {
            if ((i % n) != 0 && pos == 1)
            {
                cout << i << endl;
                break;
            }
            pos--;
        }
    }

    return 0;

}
