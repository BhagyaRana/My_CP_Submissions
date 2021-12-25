#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
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

ll pos = 0;

class Hash
{
    int BUCKET; // No. of buckets
    // Pointer to an array containing buckets
    list<int> *table;

public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }

    void displayHash(int d, int k, int l, int r);
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    pos++;
    table[index].push_back(pos);
}

// table[d]
// for(auto)

// function to display hash table
void Hash::displayHash(int d, int k, int l, int r)
{
    int i = d;
    int count = 0;
    int flag = 0;
    // cout << i;
    if (k <= table[i].size())
    {
        for (auto x : table[i])
        {
            count++;
            if (count == k)
            {
                flag = 1;
                if (x >= l && x <= r)
                {
                    cout << x << endl;
                    break;
                }
                else
                {
                    cout << "-1" << endl;
                    break;
                }
            }
        }
    }

    if (flag == 0)
        cout << "-1" << endl;
}

int arr[1000001];

int main()
{
    b_v_r();
    int n, q;
    cin >> n >> q;
    // mk(arr, n, int);
    Hash h(1000003);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        h.insertItem(arr[i]);
    }
    while (q--)
    {
        int d, k, l, r;
        cin >> d >> k >> l >> r;
        // Id -> d
        // kth Person
        // Range is Between l and r i inclusive
        h.displayHash(d, k, l, r);
    }

    return 0;
}
