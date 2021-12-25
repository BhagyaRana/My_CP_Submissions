#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	b_v_r();
	ll n;
	cin >> n;
	while (true)
	{
		cout << n << " ";
		if (n == 1) break;
		if (n % 2 == 0)
			n /= 2;
		else
			n = (3 * n) + 1;
	}
	cout << endl;
	return 0;
}
