#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), pos, dp(n + 1);
    unordered_map<int, int> b;
    for (int & num : a) cin >> num;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        b.insert({num, i + 1});
    }

    for (int & num : a) {
        auto i = b.find(num);
        if (i != b.end()) pos.push_back(i->second);
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i < 2) {
            dp[i] = 1;
            continue;
        }
        if (pos[i - 1] > pos[i - 2]) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }

    cout << dp[n];
}