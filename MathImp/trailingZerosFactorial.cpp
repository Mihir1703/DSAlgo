#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int n,ans=0;
        cin>>n;
        for(int i=5;i<=n;i*=5){
            ans += n/i;
        }
        cout<<ans<<endl;
    }
    return 0;
}