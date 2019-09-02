#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <string> s;
    unordered_map<string, int> umap;
    int arr[26]={};
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        s.push_back(temp);
    }
    int count=0;
    int flag = 0;
    vector <char> temp;
    string hell;
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++){
            if(arr[(int)s[i][j]-(int)'a']==0){
                arr[(int)s[i][j]-(int)'a']++;
            }
        }
        for(int j=0; j<26; j++){
            if(arr[j]>0){
                temp.push_back(char(97+j));
            }
            arr[j]=0;
        }
        string hell(temp.begin(), temp.end());
        if (umap.find(hell) == umap.end()){
            // cout<<hell<<endl;
            umap.insert(make_pair(hell, 1));
            count++;
        }
        temp.clear();
    }
    cout<<count;
}
