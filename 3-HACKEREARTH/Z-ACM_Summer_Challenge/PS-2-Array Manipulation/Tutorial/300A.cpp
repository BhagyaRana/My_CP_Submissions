#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	'\n'
#define long long ll
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();
    int n,j = 0,k = 0,l = 0;
    cin >> n;
    int arr[n];
    int pos[n],neg[n],zero[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i]==0){
            zero[j++] = arr[i];
        }
        else{
            if(arr[i]>0)
                {
                    pos[k++] = arr[i];
                }
            else
            {
                neg[l++] = arr[i];
            }
        }

    }
        if(k==0)
        { //n p 0
            cout << neg[0] <<" "<<neg[1]<<" "<<neg[2]<<"\n";
            cout << neg[0] <<" "<<neg[1]<<"\n";
            cout << zero[0] <<" "<<neg[0]<<"\n"; 
        }
        else
        {
            if(l>2&&k>1)
             {
                 cout << neg[0] <<" "<<pos[0] << "\n";
                 cout << neg[0] <<" "<< neg[1] << "\n";
                 cout << zero[0] << " "<< neg[0]<<"\n";
             }   
            else
            {
                 cout << neg[0] <<" "<<pos[0] << "\n";
                 cout << pos[0] <<" "<<pos[0] << "\n";
                 cout << zero[0] << " "<< pos[0]<<"\n";
            }   
        }

    
    return 0;
}
