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
        stack<ll> s;
        vector<ll> v;
        ll num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        // cout << endl;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            // cout << v[i] << " ";

            s.push(v[i]);
        }

        while ((!s.empty())||(s.size()>2))
        {
            
                ll top = s.top();
                cout << "top1 : "<<top << endl;
                s.pop();
                ll top2 = s.top();
                cout << "top2 : "<<top2 << endl;
                s.pop();
                if (top > top2)
                {
                    s.push(top - top2);
                    cout << "top-top2 : "<<s.top() << endl;

                }
                else
                {
                    if (top < top2)
                    {
                        s.push(top2 - top);
                        cout << "top2-top1 : "<<s.top() << endl;
                    }
                    
                }
        }
        if (s.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << s.top() << endl;
        }
    }

    return 0;
}
