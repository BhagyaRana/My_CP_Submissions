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
	freopen("op1.txt", "w", stdout);
#endif
}
int rs_count = 0;
void sort1(int* a, int* b, int* c, int val)
{
	while (*a != val)
	{
		int t = *a;
		*a = *c;
		int t2 = *b;
		*b = t;
		*c = t2;
		rs_count++;
	}
	cout << "rs_count = " << rs_count << endl;
}


void print(int *p, int n)
{
	cout << "Array : ";
	for (int i = 0; i < n; ++i)
	{
		cout << p[i];
	}
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
		cout << "check" << endl;
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
				// cout << "Before Sort Array : " << endl;
				// print(arr, n);
				cout << "Sorting " << arr[i] << " " << arr[b[i + 1]] << " " << arr[b[i + 2]] << endl;
				// sort1(&arr[i], &arr[b[i + 1]], &arr[b[i + 2]], i + 1);
				while (arr[i] != i + 1)
				{
					int t = arr[i];
					arr[i] = arr[b[i + 2]];
					int t2 = arr[b[i + 1]];
					arr[b[i + 1]] = t;
					arr[b[i + 2]] = t2;
					rs_count++;
				}
				cout << "rs_count = " << rs_count << endl;
				cout << "After Sort Array : " << endl;
				print(arr, n);
			}
		}
		if (k < rs_count)
			cout << "-1" << endl;

	}
	return 0;
}
