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
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))

lld query(vlld &BIT,lld index) 
{ 
    lld ans = 0;
    index++;
    while (index>0)
    {
        ans+=BIT[index]; // ans = max(ans,BIT[index]);
        index-=index&(-index); 
    }
    return ans;
}

void update(vlld &BIT,lld index,lld val) 
{
	lld n=sz(BIT)-1;
    index++;
    while(index<=n)
    {
	    BIT[index]+=val; // BIT[index] = max(BIT[index],val); for max element bit tree
	    index+=index&(-index); 
    }
}

void print(vlld &BIT)
{
	lld n=sz(BIT)-1;
    rep(i,0,n)
    {
        cout<<query(BIT,i)-query(BIT,i-1)<<" ";
    }
    br;
}

int main()
{
	lld n;
	cin>>n;
	
	vlld a(n);
	vlld bit(n+1);
	
	rep(i,0,n)
	{
		sn(a[i]);
		update(bit,i,a[i]);
	}
    
    while(1){
    	int index, new;		//update value at certain index
    	cin>>index>>new;
    	update(bit, index, new-a[index]);
	}
    
    while(1)
    {
    	lld l,r; 	// l,r range from 0 to n-1
    	cin>>l>>r;
    	cout<<query(bit,r)-query(bit,l-1)<<endl;
	}
    
	
	
	return 0;
}
