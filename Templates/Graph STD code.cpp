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

void dfs(lld u,vector<bool> &visited,vector<vlld> &V)
{
	visited[u]=true;
	rep(i,0,sz(V[u]))
	{
		if(!visited[V[u][i]])
		{
			dfs(V[u][i],visited,V);
		}
	}
}

void bfs(lld u,vector<bool> &visited,vector<vlld> &V)
{
	qlld q;
	q.ph(u);
	visited[u]=true;
	
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		
		rep(i,0,sz(V[u]))
		{
			if(!visited[V[u][i]])
			{
				visited[V[u][i]]=true;
				q.ph(V[u][i]);
			}
		}	
	}
}

lld minDist(lld u,lld v,vector<vlld> &V)
{
	if(u==v)
	return 0;
	
	lld n=sz(V);
    bool visited[n]={0};
    lld distance[n]={0};
    
    qlld Q;
    distance[u] = 0;
    Q.push(u);
    visited[u] = true;
    
    while (!Q.empty())
    {
        lld x = Q.front();
        Q.pop();
 
        rep(i,0,sz(V[x]))
        {
            if (!visited[V[x][i]])
            {
            	distance[V[x][i]] = distance[x]+1;
	            Q.push(V[x][i]);
	            visited[V[x][i]]=true;
	            
	            if(V[x][i]==v)
	            return distance[v];
			}
        }
    }
    return -1;
}

void APUtil(lld u,vector<bool> &visited,vector<vlld> &V,vlld &disc,vlld &low,vlld &parent,slld &ans)
{
	static lld time=0;
	lld children=0;
	visited[u]=true;
	disc[u]=low[u]=time++;
	
	rep(i,0,sz(V[u]))
	{
		lld x=V[u][i];
		if(!visited[x])
		{
			children++;
			parent[x]=u;
			APUtil(x,visited,V,disc,low,parent,ans);
			
			low[u]=min(low[u],low[x]);
			
			if(parent[u]==0 && children>1)
			ans.insert(u);
			
			if(parent[u]!=0 && low[x]>=disc[u])
			ans.insert(u);
		}
		elif(x!=parent[u])
		{
			low[u]=min(low[u],disc[x]);
		}
	}	
}

vlld articulation_point(vector<vlld> &V)
{
	lld n=sz(V)-1;
	
	vector<bool>visited(n+1,false);
	vlld disc(n+1);
	vlld low(n+1);
	vlld parent(n+1,0);
	slld ans;
	
	rep(i,1,n+1)
	{
		if(!visited[i])
		APUtil(i,visited,V,disc,low,parent,ans);
	}
	// return ans if you want set
	vlld Ans(all(ans));
	return Ans;
}

void BridgeUtil(lld u,vector<bool> &visited,vector<vlld> &V,vlld &disc,vlld &low,vlld &parent,vector<plld> &ans)
{
	static lld time=0;
	visited[u]=true;
	disc[u]=low[u]=time++;
	
	rep(i,0,sz(V[u]))
	{
		lld x=V[u][i];
		if(!visited[x])
		{
			parent[x]=u;
			BridgeUtil(x,visited,V,disc,low,parent,ans);
			low[u]=min(low[u],low[x]);
			
			if(low[x]>disc[u])
			ans.pb(mk(min(u,x),max(u,x)));
		}
		elif(x!=parent[u])
		{
			low[u]=min(low[u],disc[x]);
		}
	}	
}

vector<plld> Bridge(vector<vlld> &V)
{
	lld n=sz(V)-1;
	
	vector<bool>visited(n+1,false);
	vlld disc(n+1);
	vlld low(n+1);
	vlld parent(n+1,0);
	vector<plld> ans;
	
	rep(i,1,n+1)
	{
		if(!visited[i])
		BridgeUtil(i,visited,V,disc,low,parent,ans);
	}
	return ans;
}

vlld dijPath(lld src,vector<vector<plld> > &V)
{
	lld n=sz(V)-1;
	vlld dist(n+1,MOD);
	
	set<plld> s;
	
	s.insert(mk(0,src));
	dist[src]=0;
	
	while(!s.empty())
	{
		plld tmp = *s.begin();
		s.erase(s.begin());
		
		lld u = tmp.ss;
		
		rep(i,0,sz(V[u]))
		{
			lld v = V[u][i].ff;
			lld w = V[u][i].ss;
			
			if(dist[u]+w<dist[v])
			{
				if(dist[v]!=MOD)
				s.erase(mk(dist[v],v));
				
				dist[v]=dist[u]+w;
				s.insert(mk(dist[v],v));
			}
		}
	}
	
	return dist;
}

int main()
{
	boost;
	
	lld n,m;
	cin>>n>>m; // n nodes m edges
	
	vector<vlld>V(n+1);
	vector<bool>visited(n+1,false);
	
	rep(i,0,m)
	{
		lld a,b;
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	
	//vlld a=articulation_point(V);
	//vector<plld>b=Bridge(V);
	
	return 0;
}
