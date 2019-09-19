#include <bits/stdc++.h>

using namespace std;

int first(vector <int> &arr, int key){
    int low=arr[0], high = arr[arr.size()-1];
    int ans = -1;
    while(low<=high){
        
        int mid = low + (high-low)/2;
        int midvalue = arr[mid];
        
        if(key<midvalue){
            high = mid-1;
        }
        else if(midvalue<key){
            low = mid+1;
        }
        else if(midvalue == key){
            ans = mid;
            break;
        }
    }
    return ans;
}

int last(vector <int> &arr, int key){
    int low=arr[0], high = arr[arr.size()-1];
    int ans = -1;
    while(low<=high){
        
        int mid = low + (high-low+1)/2;
        int midvalue = arr[mid];
        
        if(key<midvalue){
            high = mid-1;
        }
        else if(midvalue<key){
            low = mid+1;
        }
        else if(midvalue == key){
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

int leastGreater(vector <int> &arr, int key){
    int low=arr[0], high = arr[arr.size()-1];
    int ans = -1;
    while(low<=high){
        
        int mid = low + (high-low+1)/2;
        int midvalue = arr[mid];
        
        if(key<midvalue){
            high = mid-1;
            ans = mid;
        }
        else if(midvalue<key){
            low = mid+1;
        }
        else if(midvalue == key){
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

int greatestSmaller(vector <int> &arr, int key){
    int low=arr[0], high = arr[arr.size()-1];
    int ans = -1;
    while(low<=high){
        
        int mid = low + (high-low+1)/2;
        int midvalue = arr[mid];
        
        if(key<midvalue){
            high = mid-1;
        }
        else if(midvalue<key){
            ans = mid;
            low = mid+1;
        }
        else if(midvalue == key){
            low = mid+1;
        }
    }
    return ans;
}

int main() {
    vector <int> arr;
    return 0;
}
