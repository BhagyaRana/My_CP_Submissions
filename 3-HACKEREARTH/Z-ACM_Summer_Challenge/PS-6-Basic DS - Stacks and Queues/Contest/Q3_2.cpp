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

    int freq[26];
    memset(freq, 0, sizeof(freq));

    int k = str.length();

    for (int i = 0; i < k; i++)
        freq[str[i] - 'a']++;

    // PAIR TO STORE CHARACTER ANS THEIR FREQUENCY

    pair<char, int> pair1[26];

    for (int i = 0; i < k; i++)
    {

        if (freq[str[i] - 'a'] != 0)
        {
            // cout << str[i] << freq[str[i] - 'a'] << " ";
            pair1[str[i] - 'a'].first = str[i];
            pair1[str[i] - 'a'].second = freq[str[i] - 'a'];
            freq[str[i] - 'a'] = 0;
        }
    }
    // cout << endl;

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << "pair1 :";
    //     cout << pair1[i].first << " : " << pair1[i].second << endl;
    // }

    // VECTOR TO STORE INDEX IN ASCENDING ORDER

    vector<int> index1;
    for (int j = 0; j < 26; j++)
    {
        if (!(pair1[j].second == 0))
        {
            index1.push_back(j);
        }
    }
    // for(int i=0;i<index1.size();i++)
    // {
    //     cout << "VECTOR:";
    //     cout << "index1[" << i <<"] = "<<index1[i] << endl;
    // }

    int lk = 0;
    int insize = index1.size();

    stack<char> s;
    char ch;

    for (int i = 0; i < k; i++)
    {

        if (str[i] == pair1[index1[lk]].first)
        {
            cout << str[i];

            pair1[index1[lk]].second -= 1;
            if (pair1[index1[lk]].second == 0)
            {
                // Empty the Stack
                if (i+1<k&&(str[i+1]==pair1[index1[insize-1]].first))
                {
                    while (s.size() > 0)
                    {
                        ch = s.top();
                        s.pop();
                        cout << ch;
                    }
                }
                lk++;
            }
        }
        else
        {
            s.push(str[i]);
        }
    }

    while (s.size() > 0)
    {
        ch = s.top();
        s.pop();
        cout << ch;
    }
    cout << endl;

    return 0;
}
