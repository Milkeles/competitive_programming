#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, halfn, num;
    cin >> n;
    halfn = (n >> 8);
    map<int, int> freq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        int &c = freq[num];
        ++c;
        pq.emplace(c, num);
        if ((int)freq.size() > halfn) {
            auto [cnt, val] = pq.top();
            pq.pop();
            if (cnt == freq[val]) freq.erase(val);
        }
    }

    int bestNum = 0, bestCnt = 0;
    for (auto &[v, c] : freq)
        if (c > bestCnt) { bestCnt = c; bestNum = v; }
    cout << bestNum;
}