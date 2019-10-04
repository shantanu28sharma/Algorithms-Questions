#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_map <int, int > u_map;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        u_map[a]++;
    }
    int target;
    cin>>target;
    unordered_map <int, int>::const_iterator got;
    int count = 0;
    for(auto i:u_map){
        got = u_map.find(target-i.first);
        if(got != u_map.end()){
            count += i.second*got->second;
            u_map[target-i.first] = 0;
        }
    }
    cout<<count;
}