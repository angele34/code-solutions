#include <bits/stdc++.h>
using namespace std;

int binSearch(int k, const vector<int>& a, int l, int r) {
    if (l > r) return -1; // not found
    int m = l + (r-l) / 2;
    if (a[m] == k) return m;
    else if (a[m] > k)
        return binSearch(k, a, l, m-1);
    else
        return binSearch(k, a, m+1, r);
}

int main() {
    vector<int> a = {1,2,3,4,5};
    int k = binSearch(5,a,0,a.size()-1);
    cout << k << endl;
}


