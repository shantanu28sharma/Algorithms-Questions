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

const lld nod=27;

class trienode
{
	public:
	trienode* children[2];
	
	trienode()
	{
		children[0]=NULL;
		children[1]=NULL;
	}
};

void deletetrie(trienode* root)
{
	if (root == NULL) return;
	
    deletetrie(root->children[0]);  
    deletetrie(root->children[1]);
    free(root);
}

string Bstring(lld n)
{
	string ans="";
	rep(i,0,nod) ans=ans+"0";
	
	lld i=nod-1;
	while(n>0)
	{
		if(n%2)
		{
			ans[i]='1';
		}
		i--;
		n=n/2;
	}
	return ans;
}

void insert(trienode* root,lld val)
{
    trienode* ptr=root;
    lld index;
    
    repd(i,nod-1,0)
    {   
        index = 1&(val>>i);
        
        if(ptr->children[index]==NULL)
        {
            ptr->children[index]= new trienode;
        }
        ptr=ptr->children[index];
    }
}

bool search(trienode* root,lld num)
{
    trienode* ptr=root;
    string key = Bstring(num);
    lld index;
    
    rep(i,0,nod)
    {
        if(key[i]=='0')
        index=0;
        else
        index=1;
        
        if(ptr->children[index]==NULL)
        return false;
        
        ptr=ptr->children[index];
    }
    return (ptr!=NULL);
}

void remove(trienode* root,lld num)
{
	trienode* ptr=root;
    string key = Bstring(num);
    lld index;
    
    vector<trienode*>v;
    
    rep(i,0,nod-1)
    {
        if(key[i]=='0')
        index=0;
        else
        index=1;
        
        if(ptr->children[index]==NULL)
        return;
        
        ptr=ptr->children[index];
        v.pb(ptr);
    }
    
    if(key[nod-1]=='0')
    index=0;
    else
    index=1;
    
    ptr->children[index]=NULL;
    
    repd(i,nod-2,0)
    {
		ptr=v[i];
		if(ptr->children[0]==NULL && ptr->children[1]==NULL)
		{
			delete ptr;
			ptr=NULL;
		}
		else
		{
			return;
		}	
	}
}

lld maxXor(trienode* root,lld val)
{
	trienode* ptr=root;
    lld index;
    lld answer=0;
    
    repd(i,nod-1,0)
    {
        if((1<<i)&val)
        index=1;
        else
        index=0;
        
        if(ptr->children[!index])
        {
            index = !index;
            answer=answer^(1<<i);
        }
        
        ptr=ptr->children[index];
    }
    return answer;
}

lld minXor(trienode* root,lld val)
{
	trienode* ptr=root;
    lld index;
    lld answer=0;
    
    repd(i,nod-1,0)
    {
        if((1<<i)&val)
        index=1;
        else
        index=0;
        
        if(!ptr->children[index])
        {
            index = !index;
            answer=answer^(1<<i);
        }
        
        ptr=ptr->children[index];
    }
    return answer;
}

lld maxXorArray(vlld a)
{
	trienode* root = new trienode;
	lld ans=0;
	lld pre=0;
	lld n=sz(a);
	
	insert(root,0);
	
	rep(i,0,n)
	{
		pre=pre^a[i];
		insert(root,pre);
		ans=max(ans,maxXor(root,pre));
	}
	
	deletetrie(root);
	
	return ans;
}

int main()
{
	
	
    return 0;
}
