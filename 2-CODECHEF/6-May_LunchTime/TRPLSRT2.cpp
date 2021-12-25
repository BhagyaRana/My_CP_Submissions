#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
// #define long long ll
#define mk(arr,n,type)   type *arr=new type[n];

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
}
int rs_count = 0;
void sort1(int &a, int &b, int &c, int val)
{
	while (a != val)
	{
		int t = a;
		a = c;
		int t2 = b;
		b = a;
		c = t2;
		rs_count++;
	}
	cout << "rs_count = " << rs_count << endl;

}
// v1 , v2 , v3 => v3, v1, v2
int main()
{
	b_v_r();
	w(t)
	{
		long long n, k;
		cin >> n >> k;
		mk(arr, n, int);
		// mk(vis, n, int);
		mk(b, n, int);
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			b[arr[i]] = i;
		}
		// INPUT TAKEN
		for (int i = 0; i < n; i++)
		{
			//Main array travese
			// Check if arr[i] = i+1 -> yes then next otherwise do cylic shifts

			if (arr[i] != i + 1)
			{
				//cyclic shift of arr[i],i+1 value container,i+2 value container
				cout << "Sorting " << arr[i] << " " << arr[b[i + 1]] << " " << arr[b[i + 2]] << endl;
				sort1(arr[i], arr[b[i + 1]], arr[b[i + 2]], i + 1);
			}
		}
		if (k < rs_count)
			cout << "-1" << endl;

	}
	return 0;
}
