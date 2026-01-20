#pragma GCC optimise("Ofast,fast-math")
#include <bits/stdc++.h>

using namespace std;

bool equal(const vector<vector<int>> & table, int & n, int & m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = table[0][0];

    for (int j = 1; j < n; ++j) dp[j][0] = dp[j-1][0] + table[j][0];
    for (int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + table[0][j];

    for (int j = 1; j < n; ++j) {
        for (int k = 1; k < m; ++k) {
            if (dp[j - 1][k] != dp[j][k - 1]) return false;
            dp[j][k] = dp[j - 1][k] + table[j][k];
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 0; i <= 10; ++i) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        bool valid = true;
        vector<vector<int>> table(n, vector<int>(m));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int j = 0; j < n; ++j) for (int k = 0; k < m; ++k) cin >> table[j][k];

        valid = equal(table, n, m);
        
        if (valid) s.push_back('Y');
        else s.push_back('N');
    }

    cout << s;

}