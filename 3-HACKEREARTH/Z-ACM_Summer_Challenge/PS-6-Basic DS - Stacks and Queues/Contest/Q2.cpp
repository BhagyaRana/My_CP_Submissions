#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
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

bool Check(string expr)
{
    stack<char> s;
    int cnt1 = 0,cntb = 0;
    char x, y;
    if (expr[0] == '1'||expr[expr.length()-1]=='1')
        return false;
    for (int i = 0; i < expr.length(); i++)
    {

        if (expr[i] == '{')
        {
            s.push(expr[i]);
            cntb++;
            continue;
        }
        if(expr[i]=='1'&&expr[i+1]=='1')
        {
            return false;
        }
        if(expr[i]=='1')
        {
            cnt1++;
        }
        if (s.empty())
            return false;

        switch (expr[i])
        {
        case '}':
            x = s.top();
            s.pop();
            if (x == '1')
                return false;
            break;
        
        }
    }
    if(cnt1!=cntb)
        return false;

    return (s.empty());
}

int main()
{
    b_v_r();
    w(t)
    {
        string str;
        cin >> str;
        if (Check(str))
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
