#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> arr(n);
    vector <int> rank;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    sort(arr.begin(), arr.end());
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        rank.push_back(n-(lower_bound(arr.begin(), arr.end(), a)-arr.begin()));
    }
    int mx = 1;
    vector <int> count(m);
    count[m-1] = 1;
    int index = m-1;
    for(int i=m-2; i>=0; i--){
        if(rank[i]==rank[i+1]){
            count[i]=count[i+1]+1;
        }
        if(count[i]>=mx){
            index = i;
            mx = count[i];
        }
    }
    cout<<rank[index];
    return 0;
}