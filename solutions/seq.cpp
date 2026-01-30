// Национална олимпиада / Областен кръг / C / 2014 / seq
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<short> nums(n+1);
    nums[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }
    sum *= 2;
    vector<int> dp(n + 1);
    dp[0] = sum;
    dp[1] = sum + nums[1];
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1];
        if (nums[i] < 0) continue;
        if (dp[i-2] + nums[i] > dp[i]) {
            dp[i] = dp[i-2] + nums[i];
        }
        // for(int j = i-2; j >= 0; --j) {
        //     if(dp[j] + nums[i] > dp[i]) {
        //         dp[i] = dp[j] + nums[i];
        //     }
        // }
    }

    cout << dp[n];
}