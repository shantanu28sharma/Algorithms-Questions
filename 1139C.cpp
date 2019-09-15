#include <bits/stdc++.h>

#define ll long long int

ll p = 1e9+7;
using namespace std;

ll power(ll x, ll y) ;

void initialize(vector <int> &A){
    for(int i=0; i<A.size(); i++){
        A[i] = i;
    }
}

int root(vector <int> &A, int i){
    while(A[i]!=i){
        i = A[i];
    }
    return i;
}

void get_union(vector <int> &A, vector <int> &size, int a, int b){
    int root_A = root(A, a);
    int root_B = root(A, b);
    if(root_A==root_B){
        return;
    }
    if(size[root_A]>size[root_B]){
        A[root_B] = A[root_A];
        size[root_A]+=size[root_B];
    }
    else{
        A[root_A] = A[root_B];
        size[root_B]+=size[root_A];
    }
}

ll good(vector <ll > &count, ll k){
    ll sum = 0;
    for(int i=0; i<count.size(); i++){
        sum=(sum+power(count[i], k))%p;
        // sum%=p;
    }
    return sum;
}

ll power(ll x, ll y) 
{ 
    ll res = 1;
    x = x % p; 
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 

int main() {
    int n;
    ll k;
    cin>>n>>k;
    vector <int> A(n), size(n, 1);
    initialize(A);
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a-=1;
        b-=1;
        if(!c){
            get_union(A, size, a, b);
        }
    }
    vector <ll> root, count;
    for(int i=0; i<n; i++){
        if(A[i]==i){
            root.push_back(i);
            count.push_back(size[i]);
        }
    }
    ll total = power(n,k);
    // cout<<total<<endl;
    ll no_good = good(count, k);
    // cout<<no_good<<endl;
    if(total<no_good){
        cout<<(total-no_good)+p;
        return 0;
    }
    cout<<total-no_good;
    // 928042611
    return 0;
}
