#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
// #define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int count = 0;
		int num = n;
		int arr[4] = {0}, i = 0;
		for (; i < 4; i++)
		{
			arr[i] = num % (10 * (i + 1));
			num = num - arr[i];
			if (arr[i] != 0)
				count++;
		}
		cout << count << endl;
		for (int i = 0; i < 4; i++)
		{
			if (arr[i] != 0)
				cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;

}
