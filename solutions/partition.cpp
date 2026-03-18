// Национална олимпиада - Национален кръг > C > 2010 > partition
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD =  1'000'000'007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> dp(n + 1, 0), pref(n + 1, 0);

    pref[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i < 3) dp[i] = 0;
        else dp[i] = pref[i-3];

        pref[i] = (pref[i-1] + dp[i]) % MOD;
        /* for (int x = 3; x <= i; x++) {
            dp[i] = (dp[i] + dp[i - x]) % MOD;
        }*/
    }

    cout << dp[n];
}
