#include <bits/stdc++.h>

using namespace std;

int minChanges(string &s, vector <vector <int> > &info, int start, int end){
    if(start>end){
        return INT_MAX;
    }
    else if(start==end){
        return 0;
    }
    else if(start==end-1){
        return (s[start] == s[end])? 0 : 1;
    }
    else if(info[start][end]>=0){
        return info[start][end];
    }
    
    int count = 0;
    
    if(s[start]==s[end]){
        count = minChanges(s, info, start+1, end-1);
        info[start][end]=count;
    }
    else{
        count = 1 + min(minChanges(s, info, start+1, end), minChanges(s, info, start, end-1));
        info[start][end] = count;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        string s;
        cin>>s;
        int start = 0, end = s.size()-1;
        // cout<<end<<endl;
        vector <vector <int> > info(end+1, vector <int>(end+1, -1));
        int count = 0;
        count = minChanges(s, info, start, end);
        cout<<count<<endl;
    }
    
    return 0;
    
}