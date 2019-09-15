#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 
int main(){
    ll n, k;
    cin>>n>>k;
    vector <ll> arr(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        arr[i] = a;
    }
    sort(arr.begin(), arr.end());
    vector <ll > diff(n/2);
    for(ll i=n/2+1; i<n; i++){
        diff[i-1-n/2] = arr[i]-arr[i-1];
    }
    ll i=0;
    int med = arr[n/2];
    if(n==1){
        cout<<k+arr[0];
        return 0;
    }
    while(k-(i+1)*diff[i]>0&&i<n/2){
        k-=(i+1)*diff[i];
        med+=diff[i];
        i++;
    }
    med+=k/(i+1);
    cout<<med;
    return 0;
} 
