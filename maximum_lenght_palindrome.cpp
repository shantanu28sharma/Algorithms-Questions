#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    int s_ind, e_ind;
    int gl_count = 0;
    for(int i=0; i < s.size(); i++){
        int count = 1;
        int j = 1;
        for(; i+j<s.size() && i-j>=0; j++){
            if(s[i+j]==s[i-j]){
                count+=2;
            }
            else{
                break;
            }
        }
        if(count>gl_count){
            s_ind = i-j+1;
            e_ind = i+j-1;
            gl_count = count;
        }
    }
    for(int i=0; i < s.size(); i++){
        int count = 0;
        int j = 1;
        for(; i+j<s.size() && i-j+1>=0; j++){
            if(s[i+j]==s[i-j+1]){
                count+=2;
            }
            else{
                break;
            }
        }
        if(count>gl_count){
            s_ind = i-j+2;
            e_ind = i+j-1;
            gl_count = count;
        }
    }
    cout<<s.substr(s_ind, gl_count)<<endl;
    return 0;
}