#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void initialize(vector <int> &A, vector <ll> &size){
    for(int i=0; i<A.size(); i++){
        A[i] = i;
        size[i] = 1;
    }
    return;
}

int root(vector <int> &A, int i){
    while(A[i]!=i){
        i = A[i];
    }
    return i;
}

void unions(vector <int> &A, vector <ll> &size, int a, int b)
{
    int root_A = root(A, a);
    int root_B = root(A, b);
    if(root_A==root_B){
    	return;
	}
    if(size[root_A] < size[root_B ])
    {
        A[ root_A ] = A[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        A[ root_B ] = A[root_A];
        size[root_A] += size[root_B];
    }
    return;
}


int main() {
    int n, m;
    cin>>n>>m;
    vector <int> A(n);
    vector <ll> size(n);
    initialize(A, size);
    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(a>0){
            int b;
            cin>>b;
            b-=1;
            for(int j=1 ;j<a; j++){
                int c;
                cin>>c;
                c-=1;
                unions(A, size, b, c);
            }
        }
    }
    for(int i=0; i<n; i++){
        int asa = root(A, i);
        cout<<size[asa]<<" ";
    }
    return 0;
}
