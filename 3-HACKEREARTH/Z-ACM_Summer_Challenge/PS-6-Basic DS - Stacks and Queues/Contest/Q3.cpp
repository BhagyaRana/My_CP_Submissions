#include <bits/stdc++.h>

using namespace std;

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

    string str;
    cin >> str;

    ll freq[26];
    memset(freq, 0, sizeof(freq));

    ll k = str.length();

    for (int i = 0; i < k; i++)
        freq[str[i] - 'a']++;

    pair<char, int> pair[26];

    for (ll i = 0; i < k; i++)
    {

        if (freq[str[i] - 'a'] != 0)
        {
            // cout << str[i] << freq[str[i] - 'a'] << " ";
            pair[str[i] - 'a'].first = str[i];
            pair[str[i] - 'a'].second = freq[str[i] - 'a'];
            freq[str[i] - 'a'] = 0;
        }
    }

    queue<char> s;
    deque<char> p, ans;

    for (ll i = 0; i < k; i++)
    {
        s.push(str[i]);
    }

    vector<int> index1;
    for (ll j = 0; j < 26; j++)
    {
        if (!(pair[j].second == 0))
        {
            index1.push_back(j);
        }
    }

    ll ed = 0;
    while (s.size() > 0)
    {
        char s_front = s.front();
        s.pop();
        p.push_back(s_front);
        if (p.back() == pair[index1[ed]].first)
        {
            char p_back = p.back();
            p.pop_back();
            ans.push_back(p_back);
            pair[index1[ed]].second -= 1;
            if (pair[index1[ed]].second == 0)
            {
                // while (p.size() > 0)
                // {
                //     char p1 = p.back();
                //     p.pop_back();
                //     ans.push_back(p1);
                // }

                ed++;
            }
        }
    }

    while (p.size() > 0)
    {
        char p1 = p.back();
        p.pop_back();
        ans.push_back(p1);
    }

    deque<char>::iterator it;
    for (it = ans.begin(); it != ans.end(); ++it)
        cout << *it;
    

    // Operation 1
    //  Remove the First ELEMENT from s and P
    // char s_front = s.front();
    // s.pop();
    // p.push(s_front);

    // Operation 2
    // char p_back = p.back();
    // p.pop_back();
    // ans.push(p_back);

    return 0;
}
