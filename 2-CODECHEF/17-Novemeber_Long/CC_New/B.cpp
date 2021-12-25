// FORGET THIS APPROACH

// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
typedef long long ll;
typedef vector<int> vi;
const ll mod = 4294967296;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
// reverse 0 based.
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
// reverse 1 based
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

//SHORT HAND
#define pb push_back
#define mp make_pair

// to be used with algorithms that processes a container
// Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()  //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

#define endl "\n"

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here
// const int sz = 300002;

// // Adjacency list representation of the tree
// vi tree[sz];
// bool vis[sz];
// vi path[sz];

// void bfs(int node)
// {
//     queue<pair<int, int>> qu;
//     qu.push({node, -1});
//     vis[node] = true;

//     while (!qu.empty())
//     {
//         pair<int, int> p = qu.front();
//         qu.pop();
//         vis[p.first] = true;
//         for (int child : tree[p.first])
//         {
//             if (!vis[child])
//             {
//                 qu.push({child, p.first});
//                 path[child] = path[p.first];
//                 path[child].push_back(p.first);
//             }
//         }
//     }
// }
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    // Number of Vertices
    int n;
    // Number of Queries
    int q;
    cin >> n >> q;

    ll wgt[n + 1] = {0};
    ll path[n + 1] = {0};
    ll depth[n + 1] = {0};

    unordered_map<pair<int, int>, int, hash_pair> memory;

    for1(i, n)
    {
        cin >> wgt[i];
    }

    int u, v;
    path[1] = -1;
    depth[1] = 1;
    // memory.insert({{1, 1}, (wgt[1] * wgt[1]) % mod});
    memory[{1, 1}] = (1ll * wgt[1] * wgt[1]) % mod;
    for0(i, n - 1)
    {
        cin >> u >> v;

        path[v] = u;
        depth[v] = depth[u] + 1;
        // memory.insert({{v, v}, (memory[{u, u}] + (wgt[v] * wgt[v]) % mod) % mod});
        memory[{v, v}] = ((memory[{u, u}]) % mod + (1ll * wgt[v] * wgt[v]) % mod) % mod;

        // u--;
        // v--;
        // tree[u].push_back(v);
        // tree[v].push_back(u);
    }

    //DEBUG

    // for1(i, n)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << endl;

    // for1(i, n)
    // {
    //     cout << path[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    // for1(i, n)
    // {
    //     cout << depth[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    // for (auto x : memory)
    // {
    //     auto p = x.first;
    //     cout << "{" << p.first << "," << p.second << "} -> " << x.second << endl;
    // }

    // cout << endl;
    // cout << endl;

    // bfs(0);

    int a, b;
    while (q--)
    {
        cin >> a >> b;

        if (a == b)
        {
            cout << (memory[{a, b}]) % mod << endl;
            continue;
        }

        // a--;
        // b--;
        ll ans = 0;

        // ans = ((ans) % mod + (wgt[a] * wgt[b]) % mod) % mod;

        // watch(ans);

        // ans = ((ans) % mod + (wgt[1] * wgt[1]) % mod) % mod;
        // int st1 = path[a];
        // int st2 = path[b];
        int st1 = a;
        int st2 = b;

        while (st1 != -1 && st2 != -1)
        {
            // watch2(path[st1], path[st2]);
            if (st1 == st2)
            {
                // cout << "Memory Used!\n";
                // cout << "-> " << memory[{st1, st2}] << endl;
                ans = (ans % mod + (memory[{st1, st2}]) % mod) % mod;
                break;
            }
            else
            {

                auto it = memory.find({st1, st2});
                if (it != memory.end())
                {
                    // Answer is Found No Need to Recompute
                    // cout << "Memory Used!\n";
                    // cout << "-> " << memory[{st1, st2}] << endl;
                    ans = (ans % mod + (memory[{st1, st2}]) % mod) % mod;
                    break;
                }
                else
                {

                    if (st1 != -1 && st2 != -1)
                        ans = ((ans) % mod + (1ll * wgt[st1] * wgt[st2]) % mod) % mod;

                    st1 = path[st1];
                    st2 = path[st2];

                    // watch2(st1, st2);
                    // cout << "Added!\n";
                    // continue;
                }
            }
        }

        // vi node1 = path[a];
        // vi node2 = path[b];
        // int sz = node1.size();
        // for (int i = 0; i < sz; i++)
        // {
        //     watch2(node1[i], node2[i]);
        //     ans = ((ans) % mod + (wgt[node1[i]] * wgt[node2[i]]) % mod) % mod;
        // }
        // cout << "Query : " << a << " " << b << endl;
        cout << ans << endl;
        if (a != b)
            memory.insert({{a, b}, ans});
    }

    // for (auto x : memory)
    // {
    //     auto p = x.first;
    //     cout << "{" << p.first << "," << p.second << "} -> " << x.second << endl;
    // }

    return 0;
}
