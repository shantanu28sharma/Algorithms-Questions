#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    // cout<<-1%5;
    int n;
    cin>>n;
    ll total = 0;
    vector <ll > arr(n);
    for(int i=0; i<n; i++){
        ll a;
        cin>>a;
        arr[i] = a;
        total += a;
    }
    // cout<<total<<endl;
    for(int i = 0; i<n; i++){
        if( total-2*arr[i]<0 || (total-2*arr[i])%2!=0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
