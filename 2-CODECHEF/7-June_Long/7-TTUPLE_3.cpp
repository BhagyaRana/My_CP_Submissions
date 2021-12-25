#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

 
ll twoPair(ll p, ll q, ll r, ll a, ll b, ll c)
{
    ll x,y;
    // pairwise 2 operations
    // pair (p,q) and (p,r)
 
        //operation + +
    x=b-q; y=c-r;
    if(x+p+y == a)
    return 2;
 
    //operation * *
    if(q!=0 && b%q == 0 && r!=0 && c%r == 0){
        x=b/q; y=c/r;
        if(x*y*p == a)
            return 2;
    }
    //operation * +
    if(q!=0 && b%q == 0)
    {
        x=b/q; y=c-r;
        if(x*p + y == a)
        return 2;
    }
    //operation + *
    if(r!=0 && c%r == 0)
    {
        x=b-q; y=c/r;
        if(y*(p+x) == a)
        return 2;
    }
 
    // pair(p,q) (q,r)
    x=a-p; y=c-r;
    if(x+q+y == b)
    return 2;
 
    //operation * *
    if(p!=0 && a%p == 0 && r!=0 && c%r == 0){
        x=a/p; y=c/r;
        if(x*y*q == b)
            return 2;
    }
    //operation * +
    if(p!=0 && a%p == 0)
    {
        x=a/p; y=c-r;
        if(x*q + y == b)
        return 2;
    }
    //operation + *
    if(r!=0 && c%r == 0)
    {
        x=a-p; y=c/r;
        if(y*(q+x) == b)
        return 2;
    }
 
 
    //pair (p,r) (r,q)
 
     x=a-p; y=b-q;
    if(x+r+y == c)
    return 2;
 
    //operation * *
    if(q!=0 && b%q == 0 && p!=0 && a%p == 0){
        y=b/q; x=a/p;
        if(x*y*r == c)
            return 2;
    }
    //operation * +
    if(p!=0 && a%p == 0)
    {
        x=a/p; y=b-q;
        if(x*r + y == c)
        return 2;
    }
    //operation + *
    if(q!=0 && b%q == 0)
    {
        x=a-p; y=b/q;
        if(y*(r+x) == c)
        return 2;
    }
 
    return -1;
}
 
ll oneAllonePair(ll p, ll q, ll r, ll a, ll b, ll c)
{
    //first op is * and pair op is also *
    ll x,y;
    //pair (p q)
    if(r!=0 && c%r == 0)
    {
        x=c/r;
        if(x!=0 && q!=0 && b%(x*q) == 0){
            y = b/(x*q);
 
            if(x*y*p == a)
             return 2;
        }
 
    }
    // pair (q r)
    if(p!=0 && a%p == 0)
    {
        x=a/p;
        if(x!=0 && q!=0 && b%(x*q) == 0)
        {
            y=b/(x*q);
 
            if(x*y*r == c)
            return 2;
        }
    }
 
    //pair (p r)
    if(q!=0 && b%q == 0)
    {
        x = b/q;
        if(x!=0 && p!=0 && a%(x*p) == 0)
        {
            y=a/(x*p);
            if(x*y*q == b)
            return 2;
        }
    }
 
    // first op is * and pair op is +
 
    //pair(p q)
    if(r!=0 && c%r == 0)
    {
        x=c/r;
        y=b-(x*q);
        if((x*p + y) == a)
        return 2;
    }
    //pair(q r)
    if(p!=0 && a%p == 0)
    {
        x=a/p;
        y=b-(x*q);
        if((x*r + y) == c)
        return 2;
    }
    //pair(p r)
    if(q!=0 && b%q == 0)
    {
        x=b/q;
        y=a-(x*p);
        if((x*r + y) == c)
        return 2;
    }
 
 
    // first op is + and pair op is *
    //pair(p q)
 
    x=c-r;
    if((x+q)!=0 && b%(x+q) == 0)
    {
        y=b/(x+q);
        if(y*(x+p) == a)
        return 2;
    }
 
    // pair(q r)
    x=a-p;
    if((x+q)!=0 && b%(x+q) == 0)
    {
        y=b/(x+q);
        if(y*(x+r) == c)
        return 2;
    }
 
    //pair (p r)
    x=b-q;
    if((x+p)!=0 && a%(x+p) == 0)
    {
        y=a/(x+p);
        if(y*(x+q) == b)
        return 2;
    }
 
    // first op is + and pair op is also +
    // pair (p q)
    x=c-r;
    y=b-q-x;
    if(x+y+p == a)
    return 2;
 
    //pair(q r)
    x=a-p;
    y=b-q-x;
    if(x+y+r == c)
    return 2;
 
    //pair(p r)
    x=b-q;
    y=a-x-p;
    if(x+y+r == c)
    return 2;
 
 
    return -1;
}
 
ll oneAlloneElement(ll p, ll q, ll r, ll a, ll b, ll c)
{
    //first op is * single element op is * or + doesnt matter
 
    if((p!=0 && a%p == 0 && q!=0 && b%q == 0 && (a/p == b/q)) ||
    (p!=0 && a%p == 0 && r!=0 && c%r == 0 && (a/p == c/r)) ||
    (q!=0 && b%q == 0 && r!=0 && c%r == 0 && (b/q == c/r)))
    return 2;
 
    // dirst op is + single element op is * or + doesnt matter
    if((a-p == b-q) || (b-q == c-r) || (a-p == c-r))
    return 2;
 
    return -1;
}
ll onePaironeElement(ll p, ll q, ll r, ll a, ll b, ll c)
{
    if(((q!=0 && b%q==0 && r!=0 && c%r==0 && b/q == c/r) || (b-q == c-r)) ||
       ((p!=0 && a%p==0 && r!=0 && c%r==0 && a/p == c/r) || (a-p == c-r)) ||
       ((q!=0 && b%q==0 && p!=0 && a%p==0 && a/p == b/q) || (b-q == a-p)))
    return 2;
 
    return -1;
}
 
 
 
int main() 
{
	// your code goes here
    b_v_r();
	w(t)
	{
	    ll p,q,r,a,b,c;
	    cin>>p>>q>>r>>a>>b>>c;
 
	    if(p==a && q==b && c==a)
	    cout<<0<<"\n";
 
	    else if(( p!= 0 && a%p == 0 && q!=0 && b%q==0 && r!=0 && c%r==0 && (a/p == b/q) && (b/q == c/r)) 
	    || ((a-p == b-q) && (b-q == c-r)) || (p==a && q==b && r!=c) ||  (p==a && r==c && q!=b)
	    || (p!=a && r==c && q==b))
	    cout<<1<<"\n";
 
	    else if(p==a && q!=b && r!=c)
	    {
	        if((q!=0 && b%q==0 && r!=0 && c%r==0 && b/q == c/r) || (b-q == c-r))
	        cout<<1<<"\n";
	        else
	        cout<<2<<"\n";
	    }
	    else if(p!=a && q==b && r!=c)
	    {
	        if((p!=0 && a%p==0 && r!=0 && c%r==0 && a/p == c/r) || (a-p == c-r))
	        cout<<1<<"\n";
	        else
	        cout<<2<<"\n";
	    }
	    else if(p!=a && q!=b && r==c)
	    {
	        if((q!=0 && b%q==0 &&  p!=0 && a%p==0 && a/p == b/q) || (b-q == a-p))
	        cout<<1<<"\n";
	        else
	        cout<<2<<"\n";
	    }
	    else
	    {
	        if(oneAlloneElement(p,q,r,a,b,c) == 2 ||
	        oneAllonePair(p,q,r,a,b,c) == 2 || twoPair(p,q,r,a,b,c)==2 || 
	        onePaironeElement(p,q,r,a,b,c) == 2||(a==b&&b==c))
	        cout<<2<<"\n";
	        else
	        cout<<3<<"\n";
 
	    }
	}
	return 0;
}