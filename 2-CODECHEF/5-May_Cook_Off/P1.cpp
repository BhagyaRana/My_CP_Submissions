#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
#define long long ll
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

bool areDistinct(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return (s.size() == arr.size());
}

void countFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
    unordered_map<int, bool> vis;
    vector<int> v1;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if(vis[arr[i]]==true)
        {
            if(arr[i-1]!=arr[i])
                {
                    flag = 0;
                }
        }
        vis[arr[i]] = true;
    }

    for (auto x : mp)
        v1.push_back(x.second);

    if (areDistinct(v1)&&flag)
        cout <<"YES"<< "\n";
    else
    {
        cout<<"NO"<< "\n";
    }
}

int main()
{
    b_v_r();
    short t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        mk(arr, n, int);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        countFreq(arr, n);
    }

    return 0;
}