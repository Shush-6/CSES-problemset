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
//    vector<vector<ll>>dp(n+1,vector<ll>(sum+1,0));
//   for(int i=0;i<=n;i++){
//     dp[i][0] = 1;
//   }

//next and current used to optimise space comp
  vector<int>nextstate(sum+1,0);//dp[n][k]
    vector<int>currentstate(sum+1,0);//dp[i][k]
    currentstate[0] = 1;
  nextstate[0] = 1;
   for(int i=n-1;i>=0;i--){
    for(int x=1;x<=sum;x++){
        ll not_pick = nextstate[x];// nextstate = dp[i+1][k]
        ll pick = 0;
        if(a[i]<=x){
         pick = currentstate[x-a[i]];//currentstate = dp[i][k]
        }
        currentstate[x] = (pick + not_pick) % mod;
    }
    nextstate = currentstate;
   }    
   cout << nextstate[sum] << endl;
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
state:
nextstate[x] = Represents the number of unique combinations to form a sub-sum x using only a suffix subset of coins (from coin index i+1 to n-1).
currentstate[x] = Represents the updated number of unique combinations to form a sub-sum x after introducing the current coin (from coin index i to n-1).
transition = n times loop
tc = O(n*sum)
sc = O(sum)
 
*/