#include <bits/stdc++.h>

using namespace std;

int n;
vector <vector <int> > arr;

void initialize(vector < vector <vector <int> > > &A){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size(); j++){
            A[i][j][0] = i;
            A[i][j][1] = j;
        }
    }
}

vector <int> root( vector < vector <vector <int> > > &A, int i, int j){
    vector <int> arr(2);
    while(A[i][j][0]!=i || A[i][j][1]!=j){
        i = A[i][j][0];
        j = A[i][j][1];
    }
    arr[0] = i;
    arr[1] = j;
    return arr;
}

void get_union(vector < vector <vector <int> > > &A, int x1, int y1, int x2, int y2){
    vector <int> root_a = root(A, x1, y1);
    vector <int> root_b = root(A, x2, y2);
    // cout<<root_a[0]<<" "<<root_b[0]<<endl;
    if(root_a[0] == root_b[0] && root_a[1]==root_b[1]){
        return;
    }
    else{
        A[root_b[0]][root_b[1]][0] = A[root_a[0]][root_a[1]][0];
        A[root_b[0]][root_b[1]][1] = A[root_a[0]][root_a[1]][1];
    }
    
}


bool check(int i, int j, int n){
    if(i>=0 && i<n && j>=0 && j<n && arr[i][j]==0){
        return true;
    }
    return false;
}

void adj(vector < vector <vector <int> > > &A, int i, int j, int n){
    if(arr[i][j]==1){
        return;
    }
    if(check(i-1, j, n)){
        get_union(A, i-1, j ,i , j);
    }
    if(check(i, j-1, n)){
        get_union(A, i, j-1 ,i , j);
    }
    if(check(i+1, j, n)){
        get_union(A, i+1, j ,i , j);
    }
    if(check(i, j+1, n)){
        get_union(A, i, j+1 ,i , j);
    }
    return ;
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
    for (int i = 0; i < n; ++i)
        arr[i].resize(n);
    vector < vector <vector <int> > > A(n, vector<vector<int> >(n,vector <int>(2,0)));
    initialize(A); 
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            arr[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj(A, i, j, n);
        }
    }
    vector <int> temp1 = root(A, x1, y1);
    int temp_x1 = temp1[0];
    int temp_y1 = temp1[1];
    temp1 = root(A, x2, y2);
    int temp_x2 = temp1[0];
    int temp_y2 = temp1[1];
    int min1 = 2*n*n;
    int a1, b1, a2=temp_x2, b2=temp_y2;
    vector <pair <int, int> > info1, info2;
    if(temp_x1==temp_x2 && temp_y1==temp_y2){
        cout<<0;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vector <int> temp = root(A, i, j);
            if(temp[0] == temp_x1 && temp[1] == temp_y1){
                info1.push_back(make_pair(i, j));
            }
            else if(temp[0] == temp_x2 && temp[1] == temp_y2){
                info2.push_back(make_pair(i, j));
            }
        }
    }
    for(int i=0; i<info1.size(); i++){
       for(int j=0; j<info2.size(); j++){
           min1 = min(dist(info1[i].first, info1[i].second, info2[j].first, info2[j].second), min1);
       } 
    }
    cout<<min1;
    return 0;
}
