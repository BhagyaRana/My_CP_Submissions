#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]

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
    w(t)
    {
        int n;
        cin >> n;
        // stack<ll> s;
        vector<ll> v;
        ll num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        // cout << endl;
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < n - 1; i++)
        {
            // cout << v[i] << " ";
            if (v[i] > v[i + 1])
            {
                v[i + 1] = v[i] - v[i + 1];
                v[i] = 0;
            }
            else
            {
                if (v[i + 1] > v[i])
                {
                    v[i + 1] = v[i + 1] - v[i];
                    v[i] = 0;
                }
                else
                {
                    if (v[i + 1] == v[i])
                    {
                        v[i] = 0;
                        v[i+1] = 0;
                        i++;
                    }
                }
            }
        }
        int sz = v.size();
        if(v[sz-1]!=0)
        {
            cout << v[sz-1] << endl;
        }
        else
        {   if(v[sz-2]==0)
                cout << "-1" << endl;
            else
            {
                cout << v[sz-1] << endl;
            }
            
        }
        
        // cout << "ANS" <<endl;
        // for(auto i : v)
        // {
        //     cout << i << " ";
        // }

        // if(v.empty())
        // {
        //     cout << "-1" << endl;
        // }
        // else
        // {
        //     cout << v.front() << endl;
        // }
        
        // cout << endl;
    }

    return 0;
}
