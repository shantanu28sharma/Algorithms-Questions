#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll ans;
    ans = n-(-3+sqrt(9+8*(n+k)))/2;
    cout<<ans;
    return 0;
}
