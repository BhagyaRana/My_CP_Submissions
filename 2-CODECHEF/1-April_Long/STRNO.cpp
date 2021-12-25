#include <bits/stdc++.h>

using namespace std;

// #define int 			 long long
#define mod 			 1000000007


void b_v_r()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 10000;
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i] && (long long)i * i <= n)
		{
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}



int myfx(int cod, int pod )
{	for (n = 1; n <= 10000; n++)
	{
		int cnt = 0, pcnt = 0;
		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				if (n / i == i)
				{
					if (is_prime[i] == true) {
						pcnt++;
					}
					cnt++;
				}

				else {
					if (is_prime[i] == true)
						pcnt++;
					if (is_prime[n / i] == true)
						pcnt++;
					cnt = cnt + 2;
				}
			}
		}
		if ((cnt == cod) && (pcnt == pod))
			return 1;
		else
			return 0;

	}

}

int32_t main()
{
	b_v_r();
	int x, k;
	short t;
	cin >> t;
	while (t--)
	{
		long long x, k, i;
		cin >> x >> k;
		ans = myfx(x, k);




	}
	return 0;
}


void SieveOfEratosthenes(int n, bool prime[],
                         bool primesquare[], int a[])
{
	for (int i = 2; i <= n; i++)
		prime[i] = true;

	for (int i = 0; i <= (n * n + 1); i++)
		primesquare[i] = false;

	prime[1] = false;

	for (int p = 2; p * p <= n; p++) {

		if (prime[p] == true) {
			// Update all multiples of p
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	int j = 0;
	for (int p = 2; p <= n; p++) {
		if (prime[p]) {
			// Storing primes in an array
			a[j] = p;

			// Update value in primesquare[p*p],
			// if p is prime.
			primesquare[p * p] = true;
			j++;
		}
	}
}

// Function to count divisors
int countDivisors(int n)
{
	// If number is 1, then it will have only 1
	// as a factor. So, total factors will be 1.
	if (n == 1)
		return 1;

	bool prime[n + 1], primesquare[n * n + 1];

	int a[n]; // for storing primes upto n

	// Calling SieveOfEratosthenes to store prime
	// factors of n and to store square of prime
	// factors of n
	SieveOfEratosthenes(n, prime, primesquare, a);

	// ans will contain total number of distinct
	// divisors
	int ans = 1;

	// Loop for counting factors of n
	for (int i = 0;; i++) {
		// a[i] is not less than cube root n
		if (a[i] * a[i] * a[i] > n)
			break;

		// Calculating power of a[i] in n.
		int cnt = 1; // cnt is power of prime a[i] in n.
		while (n % a[i] == 0) // if a[i] is a factor of n
		{
			n = n / a[i];
			cnt = cnt + 1; // incrementing power
		}

		// Calculating number of divisors
		// If n = a^p * b^q then total divisors of n
		// are (p+1)*(q+1)
		ans = ans * cnt;
	}

	// if a[i] is greater than cube root of n

	// First case
	if (prime[n])
		ans = ans * 2;

	// Second case
	else if (primesquare[n])
		ans = ans * 3;

	// Third casse
	else if (n != 1)
		ans = ans * 4;

	return ans; // Total divisors
}


