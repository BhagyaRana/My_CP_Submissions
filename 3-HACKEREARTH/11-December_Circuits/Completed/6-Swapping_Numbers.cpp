// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
// const int mod = 998244353;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)

//SHORT HAND
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end() //Forward traversal

//FIND
// find if a given value is present in a container. Container version.
// Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define endl "\n"

// COMMONLY USED TYPES
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())
#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Variables Here

// All Functions Here
// Count Number OF Inversion in The Array

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;

    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

void solve()
{
    ll n;
    cin >> n;

    int a[n] = {0};

    for0(i, n)
    {
        cin >> a[i];
    }

    bool sorted = true;
    for0(i, n)
    {
        if (a[i] != i + 1)
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        cout << 0 << endl;
        return;
    }

    ll tmp;
    int b[n];
    copy(a, a + n, b);
    // Answer With Zero Swap
    ll ans = countSwaps(b, n);

    ll cnt[n] = {0};
    ll mymin = 1e9;
    ll mymax = 0;

    for (int i = 1; i < n; i++)
    {
        int cmnt = 0;
        forc(j, 0, i - 1)
        {
            if (a[j] > a[i])
            {
                cmnt++;
            }
        }
        cnt[i] = cmnt;
        mymin = min(mymin, cmnt);
        mymax = max(mymax, cmnt);
    }

    vi idx1;
    vi idx2;
    for0(i, n)
    {
        if (cnt[i] == mymin)
        {
            idx1.pb(i);
        }
        else if (cnt[i] == mymax)
        {
            idx2.pb(i);
        }
    }

    ll sz1 = idx1.size();
    ll sz2 = idx2.size();

    for0(i, sz1)
    {
        for0(j, sz2)
        {
            int b2[n];
            copy(a, a + n, b2);
            swap(b2[idx1[i]], b2[idx2[j]]);
            ll ans1 = countSwaps(b2, n);
            ans = min(ans, ans1);
        }
    }

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // b_v_r();
    int tc = 1;
    // cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}
