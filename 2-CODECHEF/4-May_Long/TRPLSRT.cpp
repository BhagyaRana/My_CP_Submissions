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
void sort1(int &a, int &b, int &c)
{
	int t = a;
	a = c;
	int t2 = b;
	b = a;
	c = t2;
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
		mk(vis, n, int);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if (arr[i] = i + 1)
				vis[i]++;
		}
		// INPUT TAKEN
		int opcount = 0;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == 0)
			{
				int x, y, next = 2;
				// find i+1 & i+next if vis[i+next-1]!=0
				for (int j = i; j < n; j++)
				{
					if (arr[j] == i + 1)
					{
						x = j;
						if (vis[i + next - 1] == 0)
						{
							for (k = i; k < n; k++)
							{
								if (arr[k] == i + next)
								{
									y = k;
									break;
								}
							}
						}
						else
							next++;
					}

				}
				next = 2;
				while (arr[i] != i + 1 && vis[i] != 0)
				{
					cout << "Before Sorting " << arr[i] << " " << arr[x] << " " << arr[y] << "endl";
					sort1(arr[i], arr[x], arr[y]);
					opcount++;
					cout << "Operation Count : " << opcount << endl;
					cout << "After Sorting " << arr[i] << " " << arr[x] << " " << arr[y] << "endl";
				}
				vis[i] = 1;
			}

		}


	}
	return 0;
}
