// Author: H. Hristov
#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short n, m;
    cin >> n >> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<short>> a(n, vector<short>(m));
    for(int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    auto push = [&](int g, int i, int j) {
        if (g < dist[i][j]) {
            dist[i][j] = g;
            int h = m - 1 - j;
            q.emplace(g + h, i, j);
        }
    };
    for (int i = 0; i < n; ++i) push(a[i][0], i, 0);
    const int di[] = {-1,0,1};
    while (!q.empty()) {
        auto [f, i, j] = q.top(); q.pop();
        int g = f - (m - 1 - j);
        if (j == m - 1) {
            cout << g;
            return 0;
        }
        if (g > dist[i][j]) continue;
        for (int d : di) {
            int ni = i + d, nj = j + 1;
            if (ni >= 0 && ni < n && nj < m) push(g + a[ni][nj], ni, nj);
        }
    }
    return 0;
}
