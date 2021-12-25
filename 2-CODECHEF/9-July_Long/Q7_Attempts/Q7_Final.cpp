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

    ll n, q;

    cin >> n >> q;

    ll h[n + 1], taste[n + 1];

    for (ll i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        cin >> taste[i];
    }

    ll qtype, b, c;

    while (q--)
    {
        cin >> qtype >> b >> c;

        if (qtype == 1)
        {
            // 1 b k
            taste[b] = c;
        }
        else
        {
            // Query 2
            // Case 1 : Start and End are Same
            
            if(b==c)
            {
                cout << taste[b] << endl;
                continue;
            }

            //Case 2: Consecutive Elements 
            if(abs(c-b)==1)
            {
                cout << taste[c] + taste[b] << endl;
                continue;
            }

            //Case 3: Same Height Case
            if(h[b]==h[c])
            {
                cout << "-1" << endl;
                continue;
                
                // if(b<c)
                // {
                //     ll sum = 0LL;
                //     bool flag = true;
                //     for(int i = b; i<=c ; i++)
                //     {
                //         if(h[i]>h[c])
                //         {
                //             cout << "-1" << endl;
                //             flag = false;
                //             continue;
                //         }
                //         else
                //         {
                //             if(h[i]==h[c])
                //             {
                //                sum += taste[i]; 
                //             }
                //         }
                //     }
                //     if(flag)
                //         cout << sum << endl;
                //     continue;
                // }
                // else
                // {
                //     ll sum = 0LL;
                //     bool flag = true;
                //     for(int i = c; i<=b ; i++)
                //     {
                //         if(h[i]>h[b])
                //         {
                //             cout << "-1" << endl;
                //             flag = false;
                //             continue;
                //         }
                //         else
                //         {
                //             if(h[i]==h[b])
                //             {
                //                sum += taste[i]; 
                //             }
                //         }
                //     }
                //     if(flag)
                //         cout << sum << endl;
                //     continue;
                // } 
            }

            // Case 4 : Different Height
            if(h[c]>h[b])
            {
                cout << "-1" << endl;
                continue;
            }

            ll start_index,end_index;
            if(h[b]>h[c])
            {
                start_index = c;  
                end_index = b;
            }
            else
            {
                start_index = b;  
                end_index = c;
            }

            // cout << "Start_Index :" <<start_index << endl;
            // cout << "End_Index :" <<end_index << endl;

                
            if(start_index<end_index)
            {
                
                ll sum = taste[start_index];
                ll current = start_index;
                // cout << "Initial Sum : " << sum << endl;
                for(int i=start_index +1;i<=end_index;i++)
                {
                    if(h[i]>h[current])
                    {
                        // cout << "taste["<<i<<"] = "<<taste[i] << endl;
                        sum += taste[i];
                        current = i;
                    }
                }
                if(current==end_index)
                    cout << sum << endl;
                else
                    cout << "-1" << endl;
                continue;
            }
            else
            {
                ll sum = taste[start_index];
                ll current = start_index;
                // cout << "Initial Sum : " << sum << endl;
                for(int i=start_index -1;i>=end_index;i--)
                {
                    if(h[i]>h[current])
                    {
                        // cout << "taste["<<i<<"] = "<<taste[i] << endl;
                        sum += taste[i];
                        current = i;
                    }
                }

                if(current==end_index)
                    cout << sum << endl;
                else
                    cout << "-1" << endl;
                
                continue;

            }

        }
    }

    return 0;
}
