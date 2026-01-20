//Author: H. Hristov
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin >> n >> a;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a; ++j) {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }

    cout << dp[n];
    return 0;
}
