#include <bits/stdc++.h>

using namespace std;

#define w(x)    short x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int findMinSwap(int arr[] , int n)
{
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++)
	{
		vec[i].first = arr[i];
		vec[i].second = i;
	}
	sort(vec.begin(), vec.end());
	int ans = 0, c = 0, j;
	for (int i = 0; i < n; i++)
	{
		if (vec[i].second == i)
			continue;
		else
		{
			swap(vec[i].first, vec[vec[i].second].first);
			swap(vec[i].second, vec[vec[i].second].second);
		}
		if (i != vec[i].second)
			--i;
		ans++;
	}
	return ans;
}

int main()
{
	b_v_r();
	w(t)
	{
		short n, m;
		cin >> n >> m;
		mk(p, n , int);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			if (p[y - 1] < p[x - 1])
			{
				int temp = p[x - 1];
				p[x - 1] = p[y - 1];
				p[y - 1] = temp;
			}
		}
		cout << findMinSwap(p, n) << endl;
	}
	return 0;
}
