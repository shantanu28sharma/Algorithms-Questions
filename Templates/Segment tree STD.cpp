#include<bits/stdc++.h>
using namespace std;
#define MOD         1000000007
#define PI          3.14159265358979323
#define ff	first
#define ss	second
#define ph push
#define pb push_back
#define mp make_pair
#define elif else if
#define br printf("\n")
#define spc printf("")
#define sz(a) lld((a).size())
#define YES printf("YES\n")
#define NO printf("NO\n")
typedef long double ldb;
typedef long long lld;
typedef stack<lld> stlld;
typedef queue<lld> qlld;
typedef priority_queue<lld> pqlld;
typedef vector<lld> vlld;
typedef pair<lld,lld> plld;
typedef map<lld,lld> mlld;
typedef set<lld> slld;
typedef multiset<lld> mslld;
//typedef unordered_map<lld,lld> umlld;
//typedef unordered_set<lld> uslld;
#define sn(x) scanf("%lld",&x)
#define pn(x) printf("%lld ",x)
#define all(c) (c).begin(),(c).end()
#define SORT(v) sort(all(v))
#define rep(i,start,lim) for(lld i=start;i<lim;i++)
#define repd(i,start,lim) for(lld i=start;i>=lim;i--)

vlld tree(300000,-1);
vlld lazy(300000,0);
lld N=100000; 	// size of vector a 

lld func(lld a,lld b) {return min(a,b);}
lld func() {return 1<<30;} // for sum of arrays func is 0 for min=inf for max=-inf

void build(vlld &a,lld node=0,lld start=0,lld end=N-1)
{
    if(start==end)
    tree[node]=a[start];
    
    else
    {
        lld mid = (start+end)/2;
        build(a,2*node+1, start, mid);
        build(a,2*node+2, mid+1, end);
        tree[node] = func(tree[2*node+1],tree[2*node+2]);
    }
}

void update(lld id,lld val,lld node=0,lld start=0,lld end=N-1)
{
    if(start==end)
    {
        tree[node]=tree[node]+val;
    }
    else
    {
        lld mid=(start+end)/2;
        
        if(start<=id && id<=mid)
        update(id,val,2*node+1,start,mid);
        else
        update(id,val,2*node+2,mid+1,end);
        
        tree[node]=func(tree[2*node+1],tree[2*node+2]);
    }
}

lld query(lld l,lld r,lld node=0,lld start=0,lld end=N-1) /// non lazy
{
	if(r<start || end<l)
	return func();
	
	if(l<=start && end<=r)
	return tree[node];
	
	lld mid = (start+end)/2;
    lld p1 = query(l,r,2*node+1,start,mid);
    lld p2 = query(l,r,2*node+2,mid+1,end);
    return func(p1,p2);
}

/////////////////////////////////////// lazy propogation

lld query(lld l,lld r,lld node=0,lld start=0,lld end=N-1)
{
    if(r<start || end<l || start > end)
    return func();      // for sum of arrays func is 0 for min=inf for max=-inf  
    
    if(lazy[node]!=0)
    {
        // This node needs to be updated
        tree[node]+=(end-start+1)*lazy[node];            // Update it
        if(start!=end)
        {
            lazy[node*2+1]+=lazy[node];         // Mark child as lazy
            lazy[node*2+2]+=lazy[node];    // Mark child as lazy
        }
        lazy[node]=0;                 // Reset it
    }
    
    if(l<=start && end<=r)
    return tree[node];
    
    lld mid = (start+end)/2;
    lld p1 = query(l,r,2*node+1,start,mid);
    lld p2 = query(l,r,2*node+2,mid+1,end);
    return func(p1,p2);
}

void updateRange(lld l,lld r,lld val,lld node=0,lld start=0,lld end=N-1) 	// lazy propogation
{
    if(lazy[node]!=0)
    {
        // This node needs to be updated
        tree[node] = tree[node]+(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2+1] = lazy[node*2+1]+lazy[node];
            lazy[node*2+2] = lazy[node*2+2]+lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(start>end || start>r || end<l) // Current segment is not within range [l, r]
	return;
    
    if(start>=l and end<=r)
    {
        // Segment is fully within range
        tree[node] = tree[node]+(end-start+1)*val;
        
        if(start!=end)
        {
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    
    // Segment is partially within range
    
    lld mid = (start+end)/2;
    updateRange(l,r,val,node*2+1,start,mid);
    updateRange(l,r,val,node*2+2,mid+1,end);
    
    tree[node]=func(tree[node*2+1],tree[node*2+2]);
}

int main()
{
    
	
	return 0;
}

