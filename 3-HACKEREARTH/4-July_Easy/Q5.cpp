#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


// bool isSubsetSum(int set[], int n, int sum) 
// { 
//     // Base Cases 
//     if (sum == 0) 
//         return true; 
//     if (n == 0 && sum != 0) 
//         return false; 
  
//     // If last element is greater than sum, 
//     // then ignore it 
//     if (set[n - 1] > sum) 
//         return isSubsetSum(set, n - 1, sum); 
  
//     /* else, check if sum can be obtained by any  
// of the following: 
//       (a) including the last element 
//       (b) excluding the last element   */
//     return isSubsetSum(set, n - 1, sum) 
//            || isSubsetSum(set, n - 1, sum - set[n - 1]); 
// } 

// bool isSubsetSum(int set[], int n, int sum) 
// { 
//     // The value of subset[i][j] will be true if 
//     // there is a subset of set[0..j-1] with sum 
//     // equal to i 
//     bool subset[n + 1][sum + 1]; 
  
//     // If sum is 0, then answer is true 
//     for (int i = 0; i <= n; i++) 
//         subset[i][0] = true; 
  
//     // If sum is not 0 and set is empty, 
//     // then answer is false 
//     for (int i = 1; i <= sum; i++) 
//         subset[0][i] = false; 
  
//     // Fill the subset table in botton up manner 
//     for (int i = 1; i <= n; i++) { 
//         for (int j = 1; j <= sum; j++) { 
//             if (j < set[i - 1]) 
//                 subset[i][j] = subset[i - 1][j]; 
//             if (j >= set[i - 1]) 
//                 subset[i][j] = subset[i - 1][j] 
//                                || subset[i - 1][j - set[i - 1]]; 
//         } 
//     } 
  
//     /*   // uncomment this code to print table 
//      for (int i = 0; i <= n; i++) 
//      { 
//        for (int j = 0; j <= sum; j++) 
//           printf ("%4d", subset[i][j]); 
//        printf("\n"); 
//      }*/
  
//     return subset[n][sum]; 
// } 

// create a map to store solutions of subproblems
unordered_map<string, bool> lookup;

// Return true if there exists a subarray of array[0..n] with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// return true if sum becomes 0 (subset found)
	if (sum == 0)
		return true;

	// base case: no items left or sum becomes negative
	if (n < 0 || sum < 0)
		return false;

	// construct an unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(sum);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current item in the subset (arr[n]) and recur
		// for remaining items (n - 1) with remaining sum (sum - arr[n])
		bool include = subsetSum(arr, n - 1, sum - arr[n]);

		// Case 2. exclude current item n from subset and recur for
		// remaining items (n - 1)
		bool exclude = subsetSum(arr, n - 1, sum);

		// assign true if we can get subset by including or excluding the
		// current item
		lookup[key] = include || exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}


// bool isSubsetSum2(int set[], int n, int sum) 
// {
//     sort(set,set+n);
//     cout << "SET :" << endl;
//     for(int i=0;i<n;i++)
//     {
//         cout << set[i] << " ";
//     }
//     cout << endl;
//     int lb_index = upper_bound(set,set+n,sum) - set;
//     cout << "lower bound index : "<<lb_index << endl;

//     if(set[lb_index-1]==sum)
//     {
//         return true;
//     }
//     else
//     {
//         // set[lb_index] >(strict) sum
//         for(int i=0;i<lb_index;i++)
//         {
//             // set[i] + set[j] = sum
//             for(int j=i+1;j<lb_index;j++)
//             {
//                 if()
//             }
//         }
//         return false;
//     }
    
// }


int main()
{
    b_v_r();
    ll n;
    w(t)
    {
        cin >> n;
        int arr[n];
        int temp[n-1];
        int ans[n];
        memset(ans,0,sizeof(ans));

        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        
        for(int i=0;i<n;i++)
        {
            // arr[i] not to be included
            int sum = arr[i];
            int k = 0;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    temp[k] = arr[j];
                    k++;
                }
            }

            // for(int i=0;i<n-1;i++)
            // {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            // sort(temp,temp+(n-1));
            int sz = sizeof(temp) / sizeof(temp[0]);
            bool an = subsetSum(temp, sz , sum);
            // cout << an << endl;
            if(an==false) 
                ans[i] = 0;
            else
                ans[i] = 1;
            lookup.clear();
            // memset(temp,0,sizeof(temp));

        }

        for(int i=0;i<n;i++)
            cout << ans[i] << " ";

    }
        
    return 0;
}
