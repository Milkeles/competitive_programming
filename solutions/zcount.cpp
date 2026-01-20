// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,avx2,Ofast,fast-math")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll dp[20][2][2][2];   // 0: numbers, 1: zeros
bool vis[20][2][2];

ll dfs(int p, bool t, bool l, int type) {
    if (p == (int)s.size()) return type == 0;

    if (vis[p][t][l]) return dp[p][t][l][type];

    vis[p][t][l] = true;

    ll &nums = dp[p][t][l][0];
    ll &zeros   = dp[p][t][l][1];
    nums = zeros = 0;

    int hi = t ? s[p] - '0' : 9;
    for (int d = 0; d <= hi; ++d) {
        bool t2 = t && (d == hi);
        bool l2  = l && (d == 0);
        ll newNums = dfs(p + 1, t2, l2, 0);
        ll newZeros   = dfs(p + 1, t2, l2, 1);

        nums += newNums; zeros += newZeros;
        if (!l2 && d == 0) zeros += newNums;
    }
    return dp[p][t][l][type];
} // kill me pls

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    s = to_string(n);
    cout << dfs(0, 1, 1, 1);

    return 0;
}