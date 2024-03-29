#include<bits/stdc++.h>
using namespace std;
#define MOD         1000000007
#define PI          3.14159265358979323
#define ff	first
#define ss	second
#define ph push
#define pb push_back
#define mk make_pair
#define elif else if
#define br cout<<"\n";
#define spc cout<<" ";
#define sz(a) lld((a).size())
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
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
#define REP(it,temp) for(auto it=temp.begin();it!=temp.end();it++)
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct DSU
{
	const static int N = 2001;
	int n = 2001;
	lld sze[N],arr[N],temp_sze[N], flag[N];
	void init()
	{
		rep(i,0,N)
		{
			arr[i]=i;
			sze[i]=1;	
			temp_sze[i]=1;
			flag[i] = 1;
		}
	}
    
    lld root(lld x)
	{
		while(arr[x]!=x)
		{
			arr[x]=arr[arr[x]];
			x=arr[x];
		}
		return x;
	}
	
	lld prev_root(lld x)
	{
	    int temp;
		while(arr[x]!=x)
		{
			temp = x;
			x=arr[x];
		}
		return temp;
	}
    
    void get_union(lld a,lld b)
	{
		lld root_a=root(a);
		lld root_b=root(b);
		
		if(root_a==root_b)
		return;
		
		if(sze[root_a]<sze[root_b])
		{
			arr[root_a]=b;
			sze[root_b]+=sze[root_a];
            sze[b] = sze[root_b];
			temp_sze[root_b]+=temp_sze[root_a];
		}
		else
		{
			arr[root_b]=a;
			sze[root_a]+=sze[root_b];
			sze[a] = sze[root_a];
			temp_sze[root_a]+=temp_sze[root_b];
		}
	}
	
    void get_destruct(lld a,lld b)
	{
		lld root_a=root(a);
		lld root_b=root(b);
		
		if(root_a!=root_b)
		return;
		flag[root_a] = 0;
	}
	
	lld maxm(int n){
	    lld maxi = 0;
	    for(int i=1; i<=n; i++){
	        if(flag[i] && arr[i]==i){
	            maxi = max(maxi, sze[i]);
	            
	        }
	    }
	    return maxi;
	}
	
} dsu;

int main()
{
	boost;
	
	int temp;
	cin>>temp;
	
	dsu.init();
	int n, m;
	cin>>n;
	if(n==0){
	    cout<<1;
	    return 0;
	}
	rep(i, 0, n){
	    int a, b;
	    cin>>a>>b;
	    dsu.get_union(a, b);
	}
	
	cin>>m;
	
	rep(i, 0, m){
	    int a, b;
	    cin>>a>>b;
	    dsu.get_destruct(a, b);
	}
	
	lld size = dsu.maxm(n);
	cout<<size;
	return 0;
}
