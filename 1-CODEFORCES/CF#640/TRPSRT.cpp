#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > p(n + 1);
        for (int i = 0; i < n + 1; i++)
        {cin >> p[i].first; p[i].second = i;}
        vector<int> a;
        int ops = 0; vector< pair<int, int> > swaps;
        for (int i = 1; i < n + 1; i++)
        {
            if (p[i].first > p[i].second)
            {
                int v1 = p[i].second; int v2 = p[i].first; int v3 = p[v2].first;
                if (v1 == v3) {swaps.push_back(make_pair(i, p[i].first)); continue;}
                ++ops;
                a.push_back(p[i].second); a.push_back(p[i].first); a.push_back(p[p[i].first].first);
                p[v1].first = p[v3].first;
                p[v2].first = p[v2].second;
                p[v3].first = p[v3].second;
                --i;
            }
        }
        if (swaps.size() % 2 == 1 || ops + swaps.size() > k)cout << "-1" << endl;
        else
        {
            for (int i = 0; i < swaps.size(); i++)
            {
                a.push_back(swaps[i].first); a.push_back(swaps[i + 1].first); a.push_back(swaps[i + 1].second);
                a.push_back(swaps[i + 1].first); a.push_back(swaps[i].second); a.push_back(swaps[i].first);
                i += 1;
            }
            cout << a.size() / 3 << endl;
            int ptr = 0;
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << a[i + j] << " ";
                }
                cout << endl;
                i += 1;
            }
        }
    }
    return 0;
}