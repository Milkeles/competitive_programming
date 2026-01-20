#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + a[i-1];
    
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int len = 2; len <= n; len++) {
        for(int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            int sum = pref[r + 1] - pref[l];
            for(int k = l; k < r; k++) {
                int cost = sum + dp[l][k] + dp[k+1][r];
                if(cost < dp[l][r]) dp[l][r] = cost;
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}