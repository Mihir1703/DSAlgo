#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
typedef long long ll;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        ll n,ans = 0;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),greater<ll>());
        for(int i=0;i<n;i++){
            ans+=max((ll)0,v[i]-i);
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}