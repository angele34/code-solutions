#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<ll> solve(int d, int denoms[], int mx) {
    vector<ll> dp(mx+1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < d; i++) {
        for (int j = denoms[i]; j <= mx; j++) {
            dp[j] += dp[j-denoms[i]];
        }
    }
    return dp;
}

int main() {
    int d, q, denoms[12];
    cin >> d >> q;
    for(int i = 0; i < d; i++) {
        cin >> denoms[i];
    }

  	// preprocess here
    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    int mx = *max_element(queries.begin(), queries.end());
    vector<ll> dp = solve(d, denoms, mx);
  	
    for(int i : queries) {
        cout << dp[i] << '\n';
    }
}