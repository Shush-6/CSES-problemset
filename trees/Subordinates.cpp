#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
 const int mod = 1e9+7;
 const int INF = 1e9;
 
/*  Thought process

*/
void dfs(int node, vector<vector<int>>&adj , int par,vector<int>&dp){
    dp[node] = 1;
    for(auto& child:adj[node]){
        if(child==par) continue;
        dfs(child,adj,node,dp);
        dp[node]+=dp[child];
    }
}
void solve(){
   int n,v;
   cin >> n;
   int u=2;
   vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        u++;
    }
    vector<int>dp(n+1,0);
    dfs(1,adj,0,dp);
    for(int i=1;i<=n;i++){
        cout << dp[i]-1 << " ";
    }
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
 TC: O(n)
 SC: O(n)
*/