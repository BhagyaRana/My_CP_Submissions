#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

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
    int n;
    w(t)
    {
		cin >> n;
		string a;
		cin >> a;

		int s=0;
		ll ans=0;

		map<int, int> mp;

		mp[0]++; 

		for(int i=0; i<n; ++i) 
        {
			s+=a[i]-'0';//sum += digit
            // watch(s);
			ans+=mp[s-(i+1)]; 
            // watch(s-(i+1));
            // watch(mp[s-(i+1)]);
            // watch(ans);
			++mp[s-(i+1)];
		}
		cout << ans << "\n";
    }

    return 0;
}
