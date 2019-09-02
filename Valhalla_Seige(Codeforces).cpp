#include <bits/stdc++.h>

using namespace std;
vector <int> strength;


int first(int low, int high, int key) 
{ 
    int ans = -1; 
  
    while (low <= high) { 
        int mid = low + (high - low + 1) / 2; 
        int midVal = strength[mid]; 
  
        if (midVal < key) { 
  
            // if mid is less than key, all elements 
            // in range [low, mid] are also less 
            // so we now search in [mid + 1, high] 
            low = mid + 1; 
        } 
        else if (midVal > key) { 
  
            // if mid is greater than key, all elements  
            // in range [mid + 1, high] are also greater 
            // so we now search in [low, mid - 1] 
            high = mid - 1; 
        } 
        else if (midVal == key) { 
  
            // if mid is equal to key, we note down 
            //  the last found index then we search  
            // for more in left side of mid 
            // so we now search in [low, mid - 1] 
            ans = mid; 
            high = mid - 1; 
        } 
    } 
  
    return ans; 
}

int greatestlesser(int low, int high, int key) 
{ 
    int ans = -1; 
  
    while (low <= high) { 
        int mid = low + (high - low + 1) / 2; 
        int midVal = strength[mid]; 
  
        if (midVal < key) { 
  
            // if mid is less than key, all elements  
            // in range [low, mid - 1] are < key 
            // we note down the last found index, then  
            // we search in right side of mid 
            // so we now search in [mid + 1, high] 
            ans = mid; 
            low = mid + 1; 
        } 
        else if (midVal > key) { 
  
            // if mid is greater than key, all elements 
            // in range [mid + 1, high] are > key 
            // then we search in left side of mid 
            // so we now search in [low, mid - 1] 
            high = mid - 1; 
        } 
        else if (midVal == key) { 
  
            // if mid is equal to key, all elements  
            // in range [mid + 1, high] are >= key 
            // then we search in left side of mid 
            // so we now search in [low, mid - 1] 
            high = mid ; 
        } 
    } 
  
    return ans; 
} 

int main() {
    int n, q;
    cin>>n>>q;
    vector <int> arrow;
    int temp = 0;
    cin>>temp;
    strength.push_back(temp);
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        strength.push_back(strength[i-1]+a);
    }
    for(int i=0; i<q; i++){
        int b;
        cin>>b;
        if(i==0){
            arrow.push_back(b);
            cout<<n-greatestlesser(0, strength.size(), b)<<endl;;
        }
        else if(greatestlesser(0, strength.size(), arrow[i-1]+b)<n){
            cout<<n-greatestlesser(0, strength.size(), arrow[i-1]+b)<<endl;
            arrow.push_back(arrow[i-1]+b);
            
        }
        else
        if(first(0, strength.size(), b)>=0){
            cout<<first(0, strength.size(), b)<<endl;
        }
        else{
            cout<<greatestlesser(0, strength.size(), b)<<endl;
        }
    }
    
    
    
}
