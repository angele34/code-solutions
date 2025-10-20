#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x+1, 0); 
    // only 1 way to achieve an amount = 0
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] += dp[j-coins[i]] % MOD;
        }
    }

    cout << dp[x] % MOD;
}