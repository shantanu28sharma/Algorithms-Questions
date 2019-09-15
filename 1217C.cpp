// C++ program to print all possible 
// substrings of a given string 
#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 
// int count = 0;
// Function to print all sub strings 

ll decimal(string s)
{ 
    ll num = 0; 
    ll dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    ll base = 1; 
  
    ll temp = num;
    ll n = s.length()-1;
    while (n>=0) { 
        ll last_digit = s[n]-'0'; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
        n--;
    } 
  
    return dec_value; 
} 

int subString(string s, int n)  
{ 
    ll count = 0;
    // Pick starting point in outer loop 
    // and lengths of different strings for 
    // a given starting point 
    for (int i = 0; i < n; i++)  
        for (int len = 1; len <= n - i; len++) 
            // cout << s.substr(i, len) << endl; 
            if(decimal(s.substr(i, len)) == len){
                count++;
            }
    return count;
} 
  
// Driver program to test above function 
int main()  
{ 
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        std::string s;
        std::cin>>s;
        std::cout<<subString(s, s.length())<<endl; 
    }
    return 0;
} 
