#include <bits/stdc++.h>

using namespace std;

int n;

vector <vector <int> > arr,vis;

bool check(int i, int j, int n){
    if(i>=0 && i<n && j>=0 && j<n && arr[i][j]==0 && !vis[i][j]){
        // cout<<"in "<<i<<" "<<j<<endl;
        return true;
    }
    return false;
}

void dfs(vector <pair <int, int> > &arr, int i, int j){
    vis[i][j] = 1;
    arr.push_back(make_pair(i, j));
    if(check(i-1, j, n)){
        dfs(arr, i-1, j);
    }
    if(check(i, j-1, n)){
        dfs(arr, i, j-1);
    }
    if(check(i+1, j, n)){
        dfs(arr, i+1, j);
    }
    if(check(i, j+1, n)){
        dfs(arr, i, j+1);
    }
}

int dist(int x1, int y1, int x2, int y2){
    return pow(x1-x2, 2)+pow(y1-y2, 2);
}
 
int main() {
    cin>>n;
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    x1-=1;
    y1-=1;
    x2-=1;
    y2-=1;
    arr.resize(n); 
    vis.resize(n);
    
    vector <pair<int, int> > info1;
    vector <pair<int, int> > info2;
    
    for (int i = 0; i < n; ++i){
        arr[i].resize(n);
        vis[i].resize(n);
    }
        
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            vis[i][j]=0;
        }
    }
        
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<n; j++)
        {
            arr[i][j] = s[j]-'0';
        }
    }
    
    dfs(info1, x1, y1);
    dfs(info2, x2, y2);
    
    if(info1.size()==0 || info2.size()==0){
        cout<<0;
        return 0;
    }
    
    int mini = 2*n*n;
    
    for(int i=0; i<info1.size(); i++){
       for(int j=0; j<info2.size(); j++){
           mini = min(dist(info1[i].first, info1[i].second, info2[j].first, info2[j].second), mini);
       } 
    }
    cout<<mini<<endl;
    return 0;
}
