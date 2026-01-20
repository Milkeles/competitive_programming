#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bitset<1000000000> dp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        bool valid = false;

        for (ll i = 2; i * i <= num; ++i) {
            if (dp[i]) continue;

            ll cur = i * i;
            while (cur < num) {
                dp[cur] = 1;
                cur *= i;
            }
            if (cur == num) {
                valid = true;
                break;
            }
        }

        cout << (valid ? "YES\n" : "NO\n");
    }
}
