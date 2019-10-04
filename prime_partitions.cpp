#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll p = 1e9+7;
void prime(int n, vector <bool> &isPrime){
	isPrime[0] = false;
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

ll dp(ll j, string &s, vector <bool> &isPrime, vector <bool> &vis, vector <int> &pos){
    if(j==s.size()){
        return 1;
    }
    vis[j]=true;
    if(s.size()-j==1){
        pos[j]=1;
        // cout<<"in"<<s.substr(j,s.size()-j)<<endl;
        return isPrime[stoi(s.substr(j,s.size()-j))];
    }
    for(int i=1; i+j<=s.size() && i<=5; i++){
        // cout<<s.substr(j, i)<<endl;
        if(!isPrime[stoi(s.substr(j,i))] ||(vis[i+j] && pos[i+j]==0)){
            continue;
        }
        else if(isPrime[stoi(s.substr(j,i))] && vis[i+j] && pos[i+j]>0){
            pos[j] = pos[j] + pos[i+j];
        }
        else if(isPrime[stoi(s.substr(j,i))]){
            pos[j] = pos[j] + dp(i+j, s, isPrime, vis, pos);
        }
    }
    return pos[j];
}

int main() {
    int n = 99999;
    vector <bool> isPrime(n+1, true);
    prime(n, isPrime);
    
    string s;
    cin>>s;
    // cout<<s.size()<<endl;
    
    vector <bool> vis(s.size(), false);
    vector <int> pos(s.size(), 0);
    cout<<dp(0, s, isPrime, vis, pos)<<endl;
    for(int i=0; i<s.size(); i++){
        // cout<<pos[i]<<endl;
    }
    return 0;
}
