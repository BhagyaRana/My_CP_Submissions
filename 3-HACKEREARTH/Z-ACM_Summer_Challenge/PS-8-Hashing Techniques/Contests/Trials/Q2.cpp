#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
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

// Hash table size 
#define TABLE_SIZE 1000005 
  
// Used in second hash function. 
#define PRIME 1000003 
  
class DoubleHash { 
    // Pointer to an array containing buckets 
    int* hashTable; 
    int curr_size; 
  
public: 
    // function to check if hash table is full 
    bool isFull() 
    { 
  
        // if hash size reaches maximum size 
        return (curr_size == TABLE_SIZE); 
    } 
  
    // function to calculate first hash 
    int hash1(int key) 
    { 
        return (key % TABLE_SIZE); 
    } 
  
    // function to calculate second hash 
    int hash2(int key) 
    { 
        return (PRIME - (key % PRIME)); 
    } 
  
    DoubleHash() 
    { 
        hashTable = new int[TABLE_SIZE]; 
        curr_size = 0; 
        for (int i = 0; i < TABLE_SIZE; i++) 
            hashTable[i] = -1; 
    } 
  
    // function to insert key into hash table 
    void insertHash(int key) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) { 
                // get newIndex 
                int newIndex = (index + i * index2) % TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
  
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
    // function to search key in hash table 
    void search(int key) 
    { 
        int index1 = hash1(key); 
        int index2 = hash2(key); 
        int i = 0; 
        while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key) { 
            if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1) { 
                cout << key << " does not exist" << endl; 
                return; 
            } 
            i++; 
        } 
        cout << key << " found" << endl; 
    } 
  
    // function to display the hash table 
    void displayHash() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
}; 

int main()
{
    b_v_r();
    unsigned int n,q;
    cin >> n >> q;
    
    
        
    return 0;
}
