#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int k=0; k<t; k++)
    {
        int n;
        cin>>n;
        vector <vector <int> > arr(n, vector <int >(n, 0));
        vector <int> diff(n, 0);
        vector <int> temp(n, 0);
        for(int i = 0; i<n; i++){
            for(int j=0; j<i+1; j++){
                int a;
                cin>>a;
                arr[i][j] = a;
                if(i-1<0 && j-1<0){
                    diff[j] = arr[i][j];
                }
                else if(j-1<0){
                    diff[j] = temp[j]+arr[i][j];
                }
                else{
                    diff[j] = max(temp[j-1]+arr[i][j], temp[j]+arr[i][j]);
                }
            }
            for(int j=0; j<i+1; j++){
                temp[j] = diff[j];
            }
        }
        sort(diff.begin(), diff.end());
        cout<<diff[n-1]<<endl;
    }
    return 0;
}
