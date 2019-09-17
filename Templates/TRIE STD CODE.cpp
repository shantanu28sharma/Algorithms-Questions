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

const lld NUM = 62;

class trienode
{
	public:
	trienode* children[NUM];
	lld weight;
	bool isendofword;
	
	trienode()
	{
	    rep(i,0,NUM)
	    {
	        children[i]=NULL;
	    }
	    weight=0;
	    isendofword=false;
	}
};

lld cti(char c)	// char to integer
{
	// 	a=0 z=25, 0=26 9=35, A=36 Z=61
	
	if('a'<=c && c<='z')
	{
		lld ans;
		ans = c-'a';
		return ans;
	}
	
	if('0'<=c && c<='9')
	{
		lld ans;
		ans = c-'0';
		return (ans+26);
	}
	
	if('A'<=c && c<='Z')
	{
		lld ans;
		ans = c-'A';
		return (ans+36);
	}
}

void insert(trienode* root,string key,lld wt)
{
    trienode* ptr=root;
    
    rep(i,0,key.length())
    {
        lld index = cti(key[i]);
        
        if(ptr->children[index]==NULL)
        ptr->children[index]= new trienode;
        
		ptr=ptr->children[index];
        
        if(ptr->weight<wt)
        ptr->weight=wt;
    }
    ptr->isendofword=true;
}

bool search(trienode* root,string key)
{
    trienode* ptr=root;
    rep(i,0,key.length())
    {
        lld index = cti(key[i]);
        if(ptr->children[index]==NULL)
        return false;
        
        ptr=ptr->children[index];
    }
    return (ptr!=NULL && ptr->isendofword);
}

trienode* lastchar(trienode* root,string key)
{
    trienode* ptr=root;
    rep(i,0,key.length())
    {
        lld index = cti(key[i]);
        if(ptr->children[index]==NULL)
        return NULL;
        
        ptr=ptr->children[index];
    }
    return ptr;
}

bool isempty(trienode* root)
{
    rep(i,0,NUM)
    {
        if(root->children[i]!=NULL)
        return false;
    }
    return true;
}

trienode* remove(trienode* root,string key,lld depth=0)
{
    if(root==NULL)
    return NULL;
    
    if(depth==sz(key))
    {
        root->isendofword=false;
        if(isempty(root))
        {
            delete root;
            root=NULL;
        }
        return root;
    }
    
    lld index = cti(key[depth]);
    root->children[index]=remove(root->children[index],key,depth+1);
    
    if(isempty(root)==true && root->isendofword==false)
    {
        delete root;
        root=NULL;
    }
    return root;
}

int main()
{
	trienode* root = new trienode;
	
	
    return 0;
}
