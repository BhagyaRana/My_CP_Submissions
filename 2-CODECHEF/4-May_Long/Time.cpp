#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void fun()
{
	for (int i = 0; i < 1000; i++)
	{	//Loop Khaali hai..Full Khaali..aka Empty !!
	}
}

int main()
{
	freopen("output.txt", "w", stdout);
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	fun();
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
	    chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cout << "Time taken by program is : " << fixed
	     << time_taken << setprecision(9);
	cout << " sec" << endl;
	return 0;
}