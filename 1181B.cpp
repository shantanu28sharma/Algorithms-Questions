#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll l;
    cin>>l;
    string s;
    cin>>s;
    vector <int> sum(l);
    sum[0] = s[0]-'0';
    for(int i=1; i<l; i++){
        sum[i] = sum[i-1] + s[i]-'0'; 
    }
    ll left,right;
    ll mini = stoi(s);
    for(int i=1; i<l; i++){
        if(s.substr(i, l-i)[0]!='0'){
            left  = stoi(s.substr(0, i));
            right = stoi(s.substr(i, l-i));
            mini = min(mini, left + right);
        }
    }
    cout<<mini;
}
