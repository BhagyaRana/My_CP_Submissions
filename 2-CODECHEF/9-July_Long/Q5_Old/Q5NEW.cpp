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
typedef unsigned long long int ll;
// typedef unsigned long long int ull;


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

// ll freqA[1000000001], freqB[1000000001];

int main()
{
    b_v_r();

    w(t)
    {
        // memset(freqA, 0, sizeof(freqA));
        // memset(freqB, 0, sizeof(freqB));

        int n;
        cin >> n;

        ll a[n], b[n];

        map<ll,ll> freqA;
        map<ll,ll> freqB;

        set<ll> ele;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            auto it = freqA.find(a[i]);
            if(it==freqA.end())
            {
                freqA.insert({a[i],1});
            }
            else
            {
                freqA[a[i]] += 1;
            }

            auto it2 = freqB.find(a[i]);
            if(it2==freqB.end())
            {
                freqB.insert({a[i],0LL});
            }
            // freqA[a[i]]++;
            ele.insert(a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            auto it2 = freqB.find(b[i]);
            if(it2==freqB.end())
            {
                freqB.insert({b[i],1});
            }
            else
            {
                freqB[b[i]] += 1;
            }
            auto it = freqA.find(b[i]);
            if(it==freqA.end())
            {
                freqA.insert({b[i],0LL});
            }
            
            // freqB[b[i]]++;
            ele.insert(b[i]);
        }

        // for (auto itr = freqA.begin(); itr != freqA.end(); ++itr) 
        // { 
        // cout << '\t' << itr->first 
        //      << '\t' << itr->second << '\n'; 
        // } 
        // cout << endl; 

        // for (auto itr = freqB.begin(); itr != freqB.end(); ++itr) 
        // { 
        // cout << '\t' << itr->first 
        //      << '\t' << itr->second << '\n'; 
        // } 
        // cout << endl; 


        ll cost = 0ULL;
        bool flag = true;

        auto it2 = ele.begin();
        ll min_num = *it2;

        for (auto it = ele.begin(); it != ele.end(); it++)
        {
            if ((freqA[*it] + freqB[*it]) % 2 != 0)
            {
                // cout << "*it = " << *it << endl;
                flag = false;
                cout << "-1" << endl;
                break;
            }
        }

        // sort(a,a+n);
        // sort(b,b+n);

        if (flag)
        {

            ll i = 0, j = 0;

            while (i < n && j < n)
            {
                // element in a[i]
                if (freqA[a[i]] == freqB[a[i]])
                {
                    i++;
                    continue;
                }
                // element in b[j]
                if (freqA[b[j]] == freqB[b[j]])
                {
                    j++;
                    continue;
                }

                if(a[i]!=b[j])
                {
                    // cout << "Swapping"<< " i = " << i << " and j = " << j << endl;
                    cost += min((min_num * 2), min(a[i], b[j]));
                    freqA[a[i]]--;
                    freqA[b[j]]++;
                    freqB[a[i]]++;
                    freqB[b[j]]--;
                    ll temp = a[i];
                    a[i] = b[j];
                    b[j] = temp;
                    // swap(a[i],b[j]);
                    i++;
                    j++;
                    // break;
                }
                else
                {
                    i++;
                    j++;
                }
                
            }

            // cout << "A : " << endl;
            // for (int i = 0; i < n; i++)
            // {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
            // cout << "B : " << endl;
            // for (int i = 0; i < n; i++)
            // {
            //     cout << b[i] << " ";
            // }
            // cout << endl;

            cout << cost << endl;
        }
    }

    return 0;
}
