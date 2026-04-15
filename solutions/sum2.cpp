// Национална олимпиада - Общински кръг > B > 2023 > sum
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    vector<int> dp(s + 1, 1e9), a(n);
    for (int & x : a) cin >> x;
    dp[0] = 0;

    for (int i = 1; i <= s; ++i) {
        for (int x : a) {
            if (i - x >= 0) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
    }

    cout << dp[s];
}