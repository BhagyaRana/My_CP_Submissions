#include <bits/stdc++.h>
#include<string.h>

using namespace std;

#define endl "\n"

typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]

int count_min, mini1;

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

void minimum(queue<char> Que)
{
    count_min = 0;
    mini1 = 'z';
    while (!Que.empty())
    {
        if (Que.front() < mini1)
        {
            mini1 = Que.front();
            count_min = 1;
        }
        else if (Que.front() == mini1)
            {
                count_min += 1;
            }
        Que.pop();  
    }
}

int main()
{
    b_v_r();

    string str, ans = "";
    cin >> str;

    int len = str.size();

    queue<char> S;
    stack<char> p;

    for (int i = 0; i < len; i++)
    {
        S.push(str[i]);
    }

    minimum(S);

    int min = 0;

    while (!S.empty())
    {
        p.push(S.front());
        if (p.top() == mini1)
        {
            ans += p.top();
            p.pop();
            min += 1;
        }
        S.pop();
        if (min == count_min)
        {
            minimum(S);
            min = 0;
            while (!p.empty() and p.top() <= mini1)
            {
                ans += p.top();
                p.pop();
            }
        }
    }

    while (!p.empty())
    {
        ans += p.top();
        p.pop();
    }

    cout << ans;

    return 0;
}
