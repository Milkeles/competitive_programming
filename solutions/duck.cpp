// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

class DisjointUnionSet {
private:
    vector<short> rank;
    vector<short> parent;

public:
    DisjointUnionSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    short Find(short u) {
        if (parent[u] != u) parent[u] = Find(parent[u]);
        return parent[u];
    }

    bool Union(short u, short v) {
        short rootU = Find(u), rootV = Find(v);

        if (rootU == rootV) return false;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            ++rank[rootU];
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    DisjointUnionSet dsu(n);
    vector<pair<int,int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        dsu.Union(u, v);
        edges.push_back({u, v});
    }

    vector<ll> compSize(n, 0);
    for (int i = 0; i < n; ++i)
        compSize[dsu.Find(i)]++;

    vector<ll> edgeCount(n, 0);
    for (auto &e : edges)
        edgeCount[dsu.Find(e.first)]++;

    bool valid = true;
    for (int i = 0; i < n; ++i) {
        if (compSize[i] == 0) continue;
        ll k = compSize[i];
        if (edgeCount[i] != (k * (k - 1)) >> 1) {
            valid = false;
            break;
        }
    }

    cout << (valid ? "YES" : "NO");
    return 0;
}