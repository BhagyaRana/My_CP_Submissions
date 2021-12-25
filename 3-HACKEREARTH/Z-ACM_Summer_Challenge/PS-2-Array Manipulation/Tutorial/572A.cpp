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

int main()
{
    b_v_r();
    int na, nb;
    cin >> na >> nb;
    mk(ar1, na, int);
    mk(ar2, nb, int);
    int k, m;
    cin >> k >> m;
    for (int i = 0; i < na; i++)
    {
        cin >> ar1[i];
    }
    for (int i = 0; i < nb; i++)
    {
        cin >> ar2[i];
    }
    if (ar1[k - 1] < ar2[nb - 1 - m + 1])
    {
        cout << "YES"<< "\n";
    }
    else
    {
        cout << "NO"<< "\n";
    }

    return 0;
}
