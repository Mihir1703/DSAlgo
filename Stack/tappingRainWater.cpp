#include<bits/stdc++.h>
using namespace std;

int largeArea(vector<int> a){
    stack<int> s;
    int maxA = 0,i=0;
    while(i<a.size()){
        if(s.empty() || a[s.top()]>=a[i]){
            s.push(i++);
        }else{
            int t = s.top();
            s.pop();
            maxA = max(maxA,a[t]*(s.empty()? i:i-s.top()-1));
        }
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        maxA = max(maxA,a[t]*(s.empty()? i:i-s.top()-1));
    }
    return maxA;
}

int main(){
    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    cout<<largeArea(a);
    return 0;
}