#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define mk(arr,n,type)   type *arr=new type[n];

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// If there is more than one such value of Z, he should find the smallest one in the range

#define M 40

int main()
{
	b_v_r();
	w(t)
	{
		long long x, y, l, r;
		cin >> x >> y >> l >> r;
		long long z = x | y;
		bitset<M> bx(x);
		bitset<M> by(y);
		bitset<M> bz(z);
		cout << bx << endl;
		cout << by << endl;
		cout << bz << endl;
		if (z <= 2 * r)
		{
			cout << z << endl;
		}
		else
		{

		}
	}
	return 0;
}

