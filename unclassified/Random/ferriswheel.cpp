#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,x; cin >> n >> x;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll p; cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    int i = 0, j = n-1;
    int gondolas = 0;
    while(i <= j) {
        if (v[i] + v[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }
    cout << gondolas << endl;
}