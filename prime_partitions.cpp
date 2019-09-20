#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll p = 1e9+7;
void prime(int n, vector <bool> &isPrime){
    isPrime[1] = false;
    for(int p=2; p*p<=n; p++){
        if(isPrime[p]){
            for(int i=p*p; i<=n; i+=p){
                isPrime[i]=false;
            }
        }
    }
    return ;
}

ll dp(ll j, string &s, vector <bool> &isPrime, vector <bool> &vis){
    vis[j] = true;
    ll temp_count = 0;
    for(int i=1; i<=5 && i+j<=s.size(); i++){
        if(isPrime[stoi(s.substr(j, i))]==1){
            temp_count++;
        }
        if(!vis[i+j]){
            temp_count=(temp_count+dp(i+j, s, isPrime, vis))%p;
        }
    }
    return temp_count%p;
}

int main() {
    int n = 99999;
    vector <bool> isPrime(n+1, true);
    prime(n, isPrime);
    
    string s;
    cin>>s;
    cout<<s.size()<<endl;
    
    vector <bool> vis(s.size(), false);
    cout<<dp(0, s, isPrime, vis);
    
    return 0;
}
