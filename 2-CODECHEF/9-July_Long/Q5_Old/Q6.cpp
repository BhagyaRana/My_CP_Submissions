#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}





ll freqA[200001],freqB[200001];

int main()
{
    b_v_r();
    
    w(t)
    {
        memset(freqA,0,sizeof(freqA));
        memset(freqB,0,sizeof(freqB));

        int n;
        cin >> n;

        ll a[n],b[n];
        set <ll> ele;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            freqA[a[i]]++;
            ele.insert(a[i]);
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            freqB[b[i]]++;
            ele.insert(b[i]);
        }

        ll cost = 0LL;
        bool flag = true;

        auto it2=ele.begin();
        ll min_num = *it2;


        set<ll> set2;





        for(auto it=ele.begin();it!=ele.end();it++)
        {
            if((freqA[*it]+freqB[*it])%2==0)
            {
                if(freqA[*it]==freqB[*it])
                {
                    continue;
                }
                else
                {
                    set2.insert(*it);

                    // if(*it!=min_num)
                    // {
                    //     if(freqA[*it]>freqB[*it])
                    //     {
                    //         // 12 2
                    //         ll mid = (freqA[*it]+freqB[*it])/2;
                    //         // swapped -> f
                    //         ll swapnums = freqA[*it] - mid;
                    //         freqA[*it] -= swapnums;
                    //         freqB[*it] += swapnums;

                    //         cost += (swapnums*min_num);
                    //         cout << "*it : "<<*it << " swapnums : "<< swapnums << endl;  
                    //     }
                    //     else
                    //     {
                    //         // 12 2
                    //         ll mid = (freqA[*it]+freqB[*it])/2;
                    //         // swapped -> f
                    //         ll swapnums = freqB[*it] - mid;
                    //         freqB[*it] -= swapnums;
                    //         freqA[*it] += swapnums;
                    //         cost += (swapnums*min_num);
                    //         cout << "*it : "<<*it << "swapnums : "<< swapnums << endl;  
                    //     }
                    // }
                    // else
                    // {
                    //     continue;
                    // }
                }  
            }
            else
            {
                flag = false;
                cout << "-1" << endl;
                break;
            }
            
        }

        vector<ll> A;
        vector<ll> B;

        for(auto it=set2.begin();it!=set2.end();it++)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==(*it))
                    A.push_back(*it);
                if(b[i]==(*it))
                    B.push_back(*it);
            }
            
        }

        ll sza = A.size();
        ll szb = B.size();
        cout << "VECTOR A : ";
        for(int i=0;i<sza;i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        cout << "VECTOR B : ";
        for(int i=0;i<szb;i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;


        ll i = 0LL,j=0LL;
        while(i<sza&&j<szb)
        {
            while(freqA[A[i]]==freqB[A[i]])
            {
                i++;
                // continue;
            }
            while(freqA[B[j]]==freqB[B[j]])
            {
                j++;
                // continue;
            }

            // swap a[i] & b[j]
            // swap(A[i],B[j]);
            if((freqA[A[i]]!=freqB[A[i]])&&(freqA[B[j]]!=freqB[B[j]]))
            {

                cout << "SWAPPING : A[i] = " <<A[i] << " and B[j] = " << B[j] << endl; 
                swap(A[i],B[j]);
                cost += min(min_num*2,min(A[i],B[j]));
                cout << "cost : " << cost << endl;
                freqA[A[i]]--;
                freqB[A[i]]++;
                freqA[B[j]]++;
                freqB[B[j]]--;
                i++;
                j++;
            }
            

        }













        // for(int i=0;i<sza;i++)
        // {
        //     if(freqA[A[i]]>2&&freqB[B[i]]>2&&(freqA[A[i]]!=freqB[B[i]]))
        //     {
        //         ll m_min = min(A[i],B[i]);
        //         if(m_min<(2*min_num))
        //         {
        //             cost += m_min;
                    
        //         }
        //         else
        //         {
        //             cost += (2*min_num);

        //         }
        //         freqA[A[i]]--;
        //         freqB[B[i]]--;
        //         swap(A[i],B[i]);
        //     }
            
            

        // }
        // cout << "VECTOR A : ";
        // for(int i=0;i<sza;i++)
        // {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        // cout << "VECTOR B : ";
        // for(int i=0;i<szb;i++)
        // {
        //     cout << B[i] << " ";
        // }
        // cout << endl;


        if(flag)
            cout << cost << endl;

    }
        
    return 0;
}
