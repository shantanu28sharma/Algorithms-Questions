#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> trader;
    vector <int> risk;
    vector <int> bonus;
    vector <pair<int, int> > info(n);
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        trader.push_back(a);
    }
    sort(trader.begin(), trader.end());
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        risk.push_back(a);
    }
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        bonus.push_back(a);
    }
    
    for(int i=0; i<n; i++){
        info[i] = make_pair(bonus[i], risk[i]);
    }
    
    sort(info.begin(), info.end());
    vector <int> number(n);
    
    for(int i=0; i<n; i++){
        number[i] = n-(lower_bound(trader.begin(), trader.end(), info[i].second)-trader.begin());
    }
    int count = n;
    int i = n-1;
    int profit = 0;
    while(count>0){
        profit += min(number[i],count)*info[i].first;
        count -= number[i];
        i--;
    }
    cout<<profit<<endl;
    return 0;
}