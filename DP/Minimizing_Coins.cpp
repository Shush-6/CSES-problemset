#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
 const int mod = 1e9+7;
 const int INF = 1e18;
 
/*  Thought process

*/
void solve(){
   int n,sum;
   cin >> n>> sum;
   vector<int>a(n);
   for(int i=0;i<n;i++){
       cin >> a[i];
   }
   vector<ll>dp(sum+1,INF);
   dp[0] = 0;
   for(int i=1;i<=sum;i++){
    for(const int &coin:a){
        if(i>=coin && dp[i-coin]!=INF ){
            dp[i] = min(dp[i],1+dp[i-coin]);
        }
    }
   }
   int ans = dp[sum];
    if(ans>=INF){
         ans = -1;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}
// Never forget how widely capable you are.
// Chase Excellence to Escape mediocrity.
//Don't leave until you do it, It is Easy trust yourself.

/*
state = sum+1
transition = n times loop
tc = O(n*sum)
sc = O(sum+n) 
*/