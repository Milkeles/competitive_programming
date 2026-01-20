// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,avx2,Ofast,fast-math")
#include <bits/stdc++.h>
//#define ll long long

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

bool compare(tuple<short, short, short> & a, tuple<short, short, short> & b) {
    return get<2>(a) < get<2>(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short n, m;
    cin >> n >> m;
    // Kruskal's algorithm requires sorting the edges.
    // You've learned that graphs can be stored in adjacency matrices and
    // adjacency lists, but there's also this third way called edgeList.
    vector<tuple<short, short, short>> edgeList;
    for(short i = 0; i < m; ++i) {
        short u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
    }

    int minCost = 0;
    sort(edgeList.begin(), edgeList.end(), compare);

    // Cannot just make a visited array like Prim's algorithm.
    // In Kruskal's algorithm, edges are picked in weight order, not vertex order.
    // Therefore, the cheapest edge may be one that joins two already visited vertices
    // without necesserily forming a loop.
    // Check Disjoint Union Set: https://youtu.be/z3X7Zt_zWSM?si=2zy1PcUHzVKMMjBE
    DisjointUnionSet dsu(n);
    for (auto & [u, v, w] : edgeList) {
        if (dsu.Union(u, v))
            minCost += w; 
    }

    cout << minCost;
}