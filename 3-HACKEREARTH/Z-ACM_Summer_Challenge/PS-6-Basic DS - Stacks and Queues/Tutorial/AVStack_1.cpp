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

vector<int> Stack_Basic(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    int size = n;

    // P1 -> Larger(Nearest) to Right
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {
            if (s.size() > 0 && (s.top() > arr[i]))
            {
                v.push_back(s.top());
            }
            else
            {
                while ((s.size() == 0) || (s.top() <= arr[i]))
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;

    // P2 -> Larger(Nearest) to Left

    for (int i = 0; i < size; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {
            if (s.size() > 0 && (s.top() > arr[i]))
            {
                v.push_back(s.top());
            }
            else
            {
                while ((s.size() == 0) || (s.top() <= arr[i]))
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    return v;

    // P3 -> Smaller(Nearest) to Right

    for (int i = size - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {
            if (s.size() > 0 && (s.top() < arr[i]))
            {
                v.push_back(s.top());
            }
            else
            {
                while ((s.size() == 0) || (s.top() >= arr[i]))
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;

    // P4 -> Smaller(Nearest) to Left

    for (int i = 0; i < size; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {
            if (s.size() > 0 && (s.top() < arr[i]))
            {
                v.push_back(s.top());
            }
            else
            {
                while ((s.size() == 0) || (s.top() >= arr[i]))
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
        }
        s.push(arr[i]);
    }
    return v;

    // OVER
}



int main()
{
    b_v_r();

    return 0;
}
