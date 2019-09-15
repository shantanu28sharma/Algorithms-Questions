#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector <vector <int> > vis(n, vector <int>(m, 0));
    vector <string> arr(n);
    int flag = 0;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr[i] = s;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='*' && !vis[i][j]){
                if(!flag){
                    if(i-1>=0 && i+1<n && j-1>=0 && j+1<m && arr[i-1][j]=='*' && arr[i+1][j]=='*' && arr[i][j-1]=='*' && arr[i][j+1]=='*' ){
                        flag = 1;
                        vis[i][j] = 1;
                        for(int k=i+1; k<n && arr[k][j]=='*'; k++){
                            vis[k][j] = 1;
                        }
                        for(int k=i-1; k>=0 && arr[k][j]=='*'; k--){
                            vis[k][j] = 1;
                        }
                        for(int k=j+1; k<m && arr[i][k]=='*'; k++){
                            vis[i][k] = 1;
                        }
                        for(int k=j-1; k>=0 && arr[i][k]=='*'; k--){
                            vis[i][k] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='*' && !vis[i][j]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
