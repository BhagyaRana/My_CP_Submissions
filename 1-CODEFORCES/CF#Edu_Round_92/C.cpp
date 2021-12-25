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

string leftrotate(string s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
    return s;
} 

string rightrotate(string s, int d) 
{ 
    int len = s.length();
    char end = s[len-1];
    string t = end + s.substr(0,len-1);
    return t;
} 

int main()
{
    b_v_r();
    string s;
    w(t)
    {
        cin >> s;
        int len = s.length();
        int freq[10],num;

        memset(freq,0,sizeof(freq));

        for(int i=0;i<len;i++)
        {
            num = (int) (s[i]-'0');
            freq[num]++;
        }

        if(len==2)
        {
            cout << "0" << endl;
            continue;
        }

        string left = leftrotate(s,1);
        // cout << left << endl;
        string right = rightrotate(s,1);
        // cout << right << endl;

        if((left).compare(right) == 0)
        {
            cout << "0" << endl;
            continue;
        }

        ll cnt = 0LL;
        int c2 = 0;
        for(int i=0;i<10;i++)
        {
            if(freq[i]>1)
            {
                cnt += freq[i] - 1;
            }
            else
            {
                if(freq[i]==1)
                {
                    c2++;
                }
                
            }
            
        }

        if(cnt!=0)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << c2 - 2 << endl;
        }
        
    }
        
    return 0;
}
