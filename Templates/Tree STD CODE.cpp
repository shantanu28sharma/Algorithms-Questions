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

class node
{
	public:
	lld data;
	string direction;
	node* left;
	node* right;
	node* parent;
	
	node(lld d)
	{
		data=d;
		direction="";
		left=NULL;
		right=NULL;
		parent=NULL;
	}	
};

lld height(node *root)
{
    if(root==NULL)
    return -1;
    return 1+max(height(root->left),height(root->right));
}

void preOrder(node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node *root)
{
	if(root==NULL)
	return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(node *root)
{
	if(root==NULL)
	return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void levelOrder(node *root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
    	node* ptr = q.front();
    	q.pop();
    	
        cout<<ptr->data<<" ";
        
		if(ptr->left)
        q.push(ptr->left);
        
		if(ptr->right)
		q.push(ptr->right);
    }
}

void genTopView(node *root,lld height,lld hd,map<lld,plld>&m)
{
    if(root==NULL)
    return;

    if(!m.count(hd) || m[hd].ss>height)
    m[hd] = mk(root->data,height);

    genTopView(root->left,height+1,hd-1,m);
    genTopView(root->right,height+1,hd+1,m);
}

void topView(node *root)
{
    map<lld,plld> m;
    genTopView(root,0,0,m);
    // REP(it,m)
    for(map<lld,plld>::iterator it=m.begin();it!=m.end(); it++)
    cout<<it->ss.first << " ";
}

node* findnode(lld x,node* root)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==x)
    return root;
    
    node *res=findnode(x,root->left);
    if(res!=NULL)
    return res;
    
    res=findnode(x,root->right);
    if(res!=NULL)
    return res;
}

node* insert(node* root,lld data)
{
    if (root == NULL)
    return new node(data);
    
    if (data <= root->data)
    root->left  = insert(root->left, data);
    else
    root->right = insert(root->right, data);
	 
    return root;
}

node* search(node* root,lld data) 
{
    if(root == NULL || root->data == data) 
    return root;
    
    if(root->data<data)
    return search(root->right,data);
    
    return search(root->left,data); 
}

node* lca(node* root,lld n1,lld n2)		// lowest common ancestor of binary search tree
{
    if (root == NULL)
	return NULL; 

    if (root->data > n1 && root->data > n2) 
    return lca(root->left, n1, n2); 

    if (root->data < n1 && root->data < n2) 
    return lca(root->right, n1, n2); 

    return root;
}

int main()
{
	
	
    return 0;
}
