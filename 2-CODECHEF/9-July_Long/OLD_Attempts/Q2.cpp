#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
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

ull power_of_num(ull n)
{
    ull sum = 0ULL;
    while (n)
    {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

int main()
{
    b_v_r();
    int n;
    w(t)
    {
        cin >> n;
        ull a[n],b[n],powA[n],powB[n],chef = 0ULL,morty = 0ULL;
        for(int i=0;i<n;i++)
        {
            cin >> a[i] >> b[i];
            powA[i] = power_of_num(a[i]);
            powB[i] = power_of_num(b[i]);
            if(powA[i]>powB[i])
            {
                chef++;
            }
            else
            {
                if(powB[i]>powA[i])
                {
                    morty++;
                }
                else
                {
                    chef++;
                    morty++;
                }
                
            }
        }
        if(chef>morty)
        {
            cout << "0 " << chef << endl; 
        }
        else
        {
            if(morty>chef)
            {
                cout << "1 " << morty << endl; 
            }
            else
            {
                cout << "2 " << chef << endl;
            }
        }
        
    }
        
    return 0;
}
