// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

//Based on paper "Maintenance of configurations in the plane" by Overmars and van Leeuwen, with some modifications

struct Point
{
    int64_t x, y;
    Point operator-(Point p) const
    {
        return {x - p.x, y - p.y};
    }
    int64_t cross(Point p) const
    {
        return x * p.y - y * p.x;
    }
    int64_t dot(Point p) const
    {
        return x * p.x + y * p.y;
    }
    bool operator<(Point p) const
    {
        if (y != p.y)
            return y < p.y;
        return x < p.x;
    }
    bool operator==(Point p) const
    {
        return x == p.x && y == p.y;
    }
    Point operator-() const
    {
        return {-x, -y};
    }
};

int64_t cross(Point a, Point b, Point c)
{
    return (b - a).cross(c - a);
}

class LeftHull
{
    vector<Point> ps;
    struct Node
    {
        int bl, br;
        int L, R;
        int lchd, rchd;
    };
    vector<Node> nodes;
    int root;
    bool isleaf(int w)
    {
        return nodes[w].lchd == -1 && nodes[w].rchd == -1;
    }
    void pull(int w)
    {
        assert(!isleaf(w));
        int l = nodes[w].lchd, r = nodes[w].rchd;
        int64_t split_y = ps[nodes[r].L].y;
        while (!isleaf(l) || !isleaf(r))
        {
            int a = nodes[l].bl, b = nodes[l].br,
                c = nodes[r].bl, d = nodes[r].br;
            if (a != b && cross(ps[a], ps[b], ps[c]) > 0)
            {
                l = nodes[l].lchd;
            }
            else if (c != d && cross(ps[b], ps[c], ps[d]) > 0)
            {
                r = nodes[r].rchd;
            }
            else if (a == b)
            {
                r = nodes[r].lchd;
            }
            else if (c == d)
            {
                l = nodes[l].rchd;
            }
            else
            {
                int64_t s1 = cross(ps[a], ps[b], ps[c]);
                int64_t s2 = cross(ps[b], ps[a], ps[d]);
                assert(s1 + s2 >= 0);
                if (s1 + s2 == 0 || s1 * ps[d].y + s2 * ps[c].y < split_y * (s1 + s2))
                {
                    l = nodes[l].rchd;
                }
                else
                {
                    r = nodes[r].lchd;
                }
            }
        }
        nodes[w].bl = nodes[l].L;
        nodes[w].br = nodes[r].L;
    }
    void build(int w, int L, int R)
    {
        nodes[w].L = L;
        nodes[w].R = R;
        if (R - L == 1)
        {
            nodes[w].lchd = nodes[w].rchd = -1;
            nodes[w].bl = nodes[w].br = L;
        }
        else
        {
            int M = (L + R) / 2;
            nodes[w].lchd = w + 1;
            nodes[w].rchd = w + 2 * (M - L);
            build(nodes[w].lchd, L, M);
            build(nodes[w].rchd, M, R);
            pull(w);
        }
    }
    int erase(int w, int L, int R)
    {
        if (R <= nodes[w].L || L >= nodes[w].R)
            return w;
        if (L <= nodes[w].L && R >= nodes[w].R)
            return -1;
        nodes[w].lchd = erase(nodes[w].lchd, L, R);
        nodes[w].rchd = erase(nodes[w].rchd, L, R);
        if (nodes[w].lchd == -1)
            return nodes[w].rchd;
        if (nodes[w].rchd == -1)
            return nodes[w].lchd;
        pull(w);
        return w;
    }
    //only works for whole hull
    void get_hull(int w, int l, int r, vector<int> &res)
    {
        if (isleaf(w))
        {
            res.push_back(nodes[w].L);
        }
        else if (r <= nodes[w].bl)
        {
            get_hull(nodes[w].lchd, l, r, res);
        }
        else if (l >= nodes[w].br)
        {
            get_hull(nodes[w].rchd, l, r, res);
        }
        else
        {
            assert(l <= nodes[w].bl && nodes[w].br <= r);
            get_hull(nodes[w].lchd, l, nodes[w].bl, res);
            get_hull(nodes[w].rchd, nodes[w].br, r, res);
        }
    }

public:
    LeftHull(const vector<Point> &ps) : ps(ps), nodes(ps.size() * 2), root(0)
    {
        build(0, 0, ps.size());
    }
    vector<int> get_hull()
    {
        if (root == -1)
            return {};
        vector<int> res;
        get_hull(root, 0, ps.size() - 1, res);
        return res;
    }
    void erase(int L)
    {
        root = erase(root, L, L + 1);
    }
};

vector<Point> ps;
map<Point, int> id;

int layer[1000005];
int ans[1000005];

ll fib[3010];
ll cfib[3010];

void init_fib()
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 3010; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cfib[0] = 0;
    for (int i = 1; i < 3010; i++)
    {
        cfib[i] = fib[i] + cfib[i - 1];
    }
}

void solve()
{
    int N;
    ll cost;
    cin >> N >> cost;
    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        ps.push_back({X, Y});
        id[{X, Y}] = i;
    }

    sort(ps.begin(), ps.end());
    struct LeftHull left(ps);

    reverse(ps.begin(), ps.end());
    for (auto &p : ps)
    {
        p = -p;
    }

    struct LeftHull right(ps);
    for (auto &p : ps)
    {
        p = -p;
    }
    reverse(ps.begin(), ps.end());

    for (int l = 1, cnt = 0; cnt < N; l++)
    {
        set<int> hull;
        for (int i : left.get_hull())
        {
            hull.insert(i);
        }
        for (int i : right.get_hull())
        {
            hull.insert(N - 1 - i);
        }
        for (int i : hull)
        {
            assert(!layer[i]);
            cnt++;
            layer[i] = l;
            left.erase(i);
            right.erase(N - 1 - i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans[id[ps[i]]] = layer[i];
    }

    set<int> myset;

    for (int i = 0; i < N; i++)
    {
        // printf("%d\n", ans[i]);
        myset.insert(ans[i]);
    }

    ll peels = myset.size();
    double ans = (double)(cost * cfib[peels] * (1.0)) / (double)peels;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init_fib();

    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
