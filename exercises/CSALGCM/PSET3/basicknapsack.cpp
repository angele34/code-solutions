#include <bits/stdc++.h>

#define MOD 1000000007LL
#define ll long long
using namespace std;

int solve(int n, int c, int ws[]){
    vector<vector<ll>> dp(n+1, vector<ll>(c+1, 0));
    
    // choosing nothing = 1 way (the empty knapsack)
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            // fill the current row with the previous row's val
            // to count the num of ways as before
            dp[i][j] = dp[i-1][j];
            if (ws[i-1] <= j) 
                dp[i][j] += dp[i-1][j-ws[i-1]] % MOD;
        }
    }
    ll ans = 0;
    for (int j = 0; j <= c; j++)
        ans += dp[n][j] % MOD;
    return ans % MOD;
}
int main() {
    int n, c, ws[2000];
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> ws[i];
    }
    cout << solve(n,c,ws) << endl;
}