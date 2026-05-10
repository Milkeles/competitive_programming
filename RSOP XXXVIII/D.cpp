// RSOP XXXVIII > D
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back
using ll = long long;
using ull = unsigned long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sum(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> adj(n + 1);

        FOR(e, 1, m) {
            int i, j, s;
            cin >> i >> j >> s;
            if (sum[i][j] == -1) {
                sum[i][j] = sum[j][i] = s;
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }

        vector<int> a(n + 1, -1);
        bool found = false;

        FOR(i, 1, n) {
            if (found) break;
            for (int j : adj[i]) {
                if (j <= i) continue;
                for (int k : adj[i]) {
                    if (k == j || k <= j) continue;
                    if (sum[j][k] != -1) {
                        int sij = sum[i][j], sik = sum[i][k], sjk = sum[j][k];
                        a[i] = (sij + sik - sjk) / 2;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }

        queue<int> q;
        FOR(i, 1, n) if (a[i] != -1) { q.push(i); break; }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (a[v] == -1) {
                    a[v] = sum[u][v] - a[u];
                    q.push(v);
                }
            }
        }

        FOR(i, 1, n) cout << a[i] << " \n"[i == n];
    }
}