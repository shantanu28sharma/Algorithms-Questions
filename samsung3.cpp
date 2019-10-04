#include<bits/stdc++.h>
using namespace std;
#define MOD         1000000007
#define ff	first
#define ss	second
#define pb push_back
#define mk make_pair
#define sz(a) lld((a).size())
typedef long long lld;
typedef vector<lld> vlld;
typedef pair<lld,lld> plld;
typedef map<lld,lld> mlld;
typedef set<lld> slld;
#define all(c) (c).begin(),(c).end()
#define SORT(v) sort(all(v))
#define rep(i,start,lim) for(lld i=start;i<lim;i++)
#define repd(i,start,lim) for(lld i=start;i>=lim;i--)
#define REP(it,temp) for(auto it=temp.begin();it!=temp.end();it++)
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
	int n;
	cin>>n;
    vector <int> arr(n);
    rep(i, 0, n){
        int a;
        cin>>a;
        arr[i]=a;
    }
	sort(arr.begin(), arr.end());
	int count = 0;
	rep(i, 1, n){
	    count+=arr[i]*arr[i-1];
	    arr[i]+=arr[i-1];
	}
	cout<<count<<endl;
	
}

int main()
{
	//boost;
	lld t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}
