#include<bits/stdc++.h>
using namespace std;

const int chars = 256;

int subarray(string str, string pat){
	int len3 = str.length(); 
	str = str + str; 
	int len1 = str.length();
	int len2 = pat.length();
	
	if(len2>len1){
		cout<<"No such window exists"<<endl;
		return 0;
	}
	
	int hash_str[chars] = {0};
	int hash_pat[chars] = {0};
	
	for(int i = 0;i<len2; i++){
		hash_pat[pat[i]]++;
	}
	int start = 0, start_index = -1, min_length = INT_MAX;
	int count = 0;
	cout<<1<<endl;
	for(int i = 0; i<len1; i++){
		
		hash_str[str[i]]++;
		
		if(hash_pat[str[i]]!=0 && hash_str[str[i]]<=hash_pat[str[i]]){
			count++;
		}
		
		if(count==len2){
			while(hash_str[str[start]]>hash_pat[str[start]] || hash_pat[str[start]]==0){
				if(hash_str[str[start]]>hash_pat[str[start]]) hash_str[str[start]]--;
				start++;
			}
			
			int win_len = i-start+1;
			
			if(win_len<min_length && win_len<=len3){
				start_index = start;
				min_length = win_len;
				//cout<<start_index<<" "<<min_length<<endl;
			}
		}
	}
	
	if(start_index==-1){
		cout<<"No such window exists"<<endl;
		return 1;
	}
	//cout<<start_index<<" "<<min_length<<endl;
	cout<<str.substr(start_index, min_length)<<endl;
	return 2;
}

int main(){
	string str;
	string pat;
	getline(cin, str);
	getline(cin, pat);
	subarray(str, pat);
	return 1;
}
