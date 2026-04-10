// Прахосмукачка
#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a) {
        for (int &x : r) {
            cin >> x;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }

    cout << dp[n][m];
}