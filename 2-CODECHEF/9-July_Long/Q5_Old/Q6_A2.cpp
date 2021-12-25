#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}





ll freqA[200001],freqB[200001];

int main()
{
    b_v_r();
    
    w(t)
    {
        memset(freqA,0,sizeof(freqA));
        memset(freqB,0,sizeof(freqB));

        int n;
        cin >> n;

        ll a[n],b[n];
        set <ll> ele;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            freqA[a[i]]++;
            ele.insert(a[i]);
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            freqB[b[i]]++;
            ele.insert(b[i]);
        }

        ll cost = 0LL;
        bool flag = true;
        auto it2=ele.begin();
        ll min_num = *it2;
        

        for(auto it=ele.begin();it!=ele.end();it++)
        {
            if((freqA[*it]+freqB[*it])%2==0)
            {
                if(freqA[*it]==freqB[*it])
                {
                    continue;
                }
                else
                {
                    if(*it!=min_num)
                    {
                        if(freqA[*it]>freqB[*it])
                        {
                            // 12 2
                            ll mid = (freqA[*it]+freqB[*it])/2;
                            // swapped -> f
                            ll swapnums = freqA[*it] - mid;
                            freqA[*it] -= swapnums;
                            freqB[*it] += swapnums;

                            cost += (swapnums*min_num);
                            cout << "*it : "<<*it << " swapnums : "<< swapnums << endl;  
                            cout << "min_num : " << min_num<< endl; 
                        }
                        else
                        {
                            // 12 2
                            ll mid = (freqA[*it]+freqB[*it])/2;
                            // swapped -> f
                            ll swapnums = freqB[*it] - mid;
                            freqB[*it] -= swapnums;
                            freqA[*it] += swapnums;
                            cost += (swapnums*min_num);
                            cout << "*it : "<<*it << "swapnums : "<< swapnums << endl;  
                        }
                    }
                    else
                    {
                        continue;
                    }
                }  
            }
            else
            {
                flag = false;
                cout << "-1" << endl;
                break;
            }
            
        }

        if(flag)
            cout << cost << endl;

    }
        
    return 0;
}
