#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector <int> arr1, arr2;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr1.push_back(a);
    }
    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        arr2.push_back(a); 
    }
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int num;
    cin>>num;
    int diff = INT_MAX;
    int i=0, j=m-1;
    int index1=i, index2=j;
    while(j>=0 && i<=m-1){
        if(arr1[i]+arr2[j]>num){
            if(abs(arr1[i]+arr2[j]-num)<diff){
                diff = abs(arr1[i]+arr2[j]-num);
                index1=i;
                index2=j;
            }
            j--;
        }
        else if(arr1[i]+arr2[j]<num){
            if(abs(arr1[i]+arr2[j]-num)<diff){
                diff = abs(arr1[i]+arr2[j]-num);
                index1=i;
                index2=j;
            }
            i++;
        }
        else if(arr1[i]+arr2[j]==num){
            index1=i;
            index2=j;
            break;
        }
    }
    
    cout<<arr1[index1]<<" "<<arr2[index2]<<endl;
    return 0;
}
