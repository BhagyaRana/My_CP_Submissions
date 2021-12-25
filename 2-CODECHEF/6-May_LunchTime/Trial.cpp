#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n];

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	b_v_r();
	bitset<64> bset(pow(10, 12));
	bitset<40> bset2(pow(10, 12));
	// bset[0] = 1;

	cout << bset << endl;
	cout << bset2 << endl;
	cout << bset.count() << endl;
	return 0;
}
