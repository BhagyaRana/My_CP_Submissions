#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;

    Graph(int v)
    {
        V = v;
        adj = new list<int>[V];
    }

    void addedge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void colors(int s)
    {
        bool *visited = new bool[V]{0};
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;
        color[s] = 0; 
        queue<int> q;
        q.push(s);
        map<int,int> mp;

        while (!q.empty())
        {

            int f = q.front();
            q.pop();
            // We have visited index "f"
            if (visited[f] == false)
            {
                visited[f] = true;
            }
            // Adjacency List of "f" Check
            for (auto i : adj[f])
            {
                // Not Visited and Not Coloured
                if (visited[i] == false && color[i] == -1)
                {
                    color[i] = 1 - color[f];
                    q.push(i);
                }
                if (visited[i] == true && color[i] == color[f])
                    color[f] = color[f] + 1;
            }

            // cout << f << "---->" << color[f] << " " << endl;
            auto itr = mp.find(color[f]);
            if(itr==mp.end())
                mp.insert(pair<int,int>(color[f],1));
            else
            {
                mp[color[f]]++;
            }
        }
        map<int, int>::iterator itr;
        cout<<mp.size()<<endl; 
        for (itr = mp.begin(); itr != mp.end(); ++itr) 
        { 
            cout << itr->second << " "; 
        } 
    }
};

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

    int  n, m, a, b;
    cin>> n;
    m = n - 1;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addedge(a-1, b-1);
    }
    g.colors(0);

    return 0;
}