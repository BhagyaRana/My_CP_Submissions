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
        int n;
        cin >> n;
        mk(str1, n + 1, char);
        mk(str2, n + 1 , char);
        gets(str1);
        gets(str2);
        mk(bindex, n , int);
        memset(bindex, 0, sizeof(bindex));
        int j = 0;
        int i=0;
        int flag = 0;
        int ca1 = 0,cb1 = 0,ca2 = 0,cb2 = 0;
        int aindex = 0;
        rep(i,n)
        {
            if((int)str1[i] != (int)str2[i])
            {
                if(str1[i]=='a')
                {
                    cout << "-1" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    cb1++;ca2++;
                    bindex[j] = i;
                    j++;
                }
            }
            else
            {
                if(str1[i]=='a')
                {
                    ca1++;
                    ca2++;
                    aindex = i;
                }
                else
                {
                    cb1++;
                    cb2++;
                }   
            }
            
        }
        if(flag!=1)
        {
            if(ca1==0&&cb1>0)
            {
                cout<<"-1here"<<endl;
            }
            else
            {
                cout << "1" << endl;
                cout << cb1 + 1 << " " << aindex << " " ;
                int l=0;
                rep(l,n)
                {
                    cout<<bindex[l]<<" ";
                }
                cout << endl;
            }   
        }

    }
        
    return 0;
}
