#include <bits/stdc++.h>

using namespace std;

char first_greater(char c, vector <bool> info){
    int x = c-97;
    int min = 25;
    for(int i=0; i<26; i++){
        if(info[i]==1 && i<min){
            min = i;
        }
    }
    for(int i=x+1; i<26; i++){
        if(info[i]==1){
            return i+97;
        }
    }
    return min+97;
}

int main() {
    
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    string s2(k, '*');
    vector <bool> info(26, 0);
    for (int i=0; i<n; i++){
        info[s[i]-97] = 1;
    }
    if (n>=k){
        int i;
        for(i=k-1; i>=0; i--){
            s2[i] = first_greater(s[i], info);
            if(s2[i]>s[i]){
                break;
            }
        }
        for(int j=0; j<i; j++){
            s2[j] = s[j];
        }
    }
    else{
        int min = 25;
        for(int i=0; i<26; i++){
            if(info[i]==1 && i<min){
                min = i;
            }
        }
        for(int i =0 ; i<n; i++){
            s2[i] = s[i];
        }
        for(int i=n; i<k; i++){
            s2[i] = min+97;
        }
    }
    cout<<s2;
    return 0;
    
}
