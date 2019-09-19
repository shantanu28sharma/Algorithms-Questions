#include <bits/stdc++.h>

using namespace std;

void update(vector <int> &bit, int val, int index){
    while(index<=bit.size()-1){
        bit[index] += val;
        index+=index&(-index);
    }
}

int sum(vector <int> &bit, int index){
    int sum = 0;
    while(index>0){
        sum+=bit[index];
        index-=index&(-index);
    }
    return sum;
}

void convert(vector <int> &arr){
    
    int n = arr.size();
    vector <int> temp(arr.size());
    for(int i=0; i<n; i++){
        temp[i] = arr[i];
    } 
    
    sort(temp.begin(), temp.end());
    
    for(int i=0; i<n; i++){
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin()+1;
    }
    
}


int main() {
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    
    vector <int> smaller_right(n);
    convert(arr);
    
    vector <int> BIT(n+1, 0);
    
    for(int i=n-1; i>=0; i--){
        smaller_right[i] = sum(BIT, arr[i]-1);
        update(BIT, 1, arr[i]);
    }
    
    for(int i=0; i<n; i++){
        cout<<smaller_right[i]<<endl;
    }
    
    return 0;
    
}
