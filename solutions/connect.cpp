#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; ++i) 
        cin >> c[i];
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sortedNodes(n);
    for (int i = 0; i < n; ++i)
        sortedNodes[i] = i + 1;
    
    sort(sortedNodes.begin(), sortedNodes.end(), [&](int x, int y) {
        return c[x] < c[y];
    });
    
    vector<vector<pair<int, long long>>> graph(n + 1);
    
    for (int u = 1; u <= n; ++u)
    {
        for (int v : adj[u])
        {
            graph[u].push_back({v, 0});
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u = sortedNodes[i];
        int v = sortedNodes[i + 1];
        long long weight = c[v] - c[u];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    
    vector<bool> inMST(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    long long ans = 0;
    int edgesAdded = 0;
    
    inMST[1] = true;
    for (auto [neighbor, weight] : graph[1])
    {
        pq.push({weight, neighbor});
    }
    
    while (!pq.empty() && edgesAdded < n - 1)
    {
        auto [weight, node] = pq.top();
        pq.pop();
        
        if (inMST[node])
            continue;
        
        inMST[node] = true;
        ans += weight;
        edgesAdded++;
        
        for (auto [neighbor, edgeWeight] : graph[node])
        {
            if (!inMST[neighbor])
            {
                pq.push({edgeWeight, neighbor});
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}