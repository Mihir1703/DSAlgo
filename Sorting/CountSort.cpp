#include<bits/stdc++.h>
using namespace std;

void CountSort(int arr[],int n){
    int k=0,ans[n];
    for(int i=0;i<n;i++){
        k = max(k,arr[i]);
    }
    k+=1;
    int cnt[k];
    for(int i=0;i<k;i++){
        cnt[i] = 0;
    }
    for(int i=0;i<n;i++){
        cnt[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        cnt[i] += cnt[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[--cnt[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    CountSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}