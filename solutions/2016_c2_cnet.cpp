#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math,no-stack-protector")
// Author: H. Hristov
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj (m, vector<int>());
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
    }

    int minT = INT_MAX;
    vector<int> res;
    vector<bool> skip (n, false);
    for (int i = 0; i < n; ++i) {

        if (adj[i].size() < 1 || skip[i]) continue;

        vector<int> dist(n, -1);
        queue<int> q;
        dist[i] = 0;
        q.push(i);

        int maxDist = 0, r = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int & v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    maxDist = max(maxDist, dist[v]);
                    q.push(v);
                    if (++r == n) break;
                }
            }
            if (r == n) break;
        }

        if (r != n) {
            for (int i = 0; i < n; ++i) {
                if (dist[i] != -1) skip[i] = true;
            }
            continue;
        }

        // if (find(dist.begin(), dist.end(), -1) != dist.end()) continue;
        if (maxDist < minT) {
            minT = maxDist;
            res = {i};
        } else if (maxDist == minT) {
            res.push_back(i);
        }
    }

    cout << res.size() << '\n';
    for (int & u : res) {
        cout << u << ' ';
    }
    return 0;
}

// Note to self: Poneze BFS i DFS obhojdat vsichi vurhove, do koito e vuzmojno
// da se stigne ot nachalniq vruh. To ako nachalniq vruh ne e posetil vsichki,
// znachi i che za vseki poseten vruh pri obhojdaneto mu ne sushtestvuva
// put do vsichki vurhove i moje da se propusne pri sledvasjto obhojdane.