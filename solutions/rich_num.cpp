// Author: H. Hristov
#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define SIZE 100001
using namespace std;

ll tree[SIZE];
ll find(int n) {
    ll res = 0;
    while (n > 0) {
        res += tree[n];
        n -= n & (-n);
    }
    return res;
}
void update(int n, int val) {
    while (n < SIZE) {
        tree[n] += val;
        n += n & (-n);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll sumDiv[SIZE];
    for (int i = 1; i < SIZE; ++i)
        for (int j = i + i; j < SIZE; j += i)
            sumDiv[j] += i;

    cin >> t;
    struct Query { int l, r, v, idx; };
    vector<Query> qr(t);
    for (int i = 0; i < t; ++i) {
        cin >> qr[i].l >> qr[i].r >> qr[i].v;
        qr[i].idx = i;
    }

    sort(qr.begin(), qr.end(), [&](const Query& a, const Query& b) {
        return a.v < b.v;
    });

    vector<pair<ll, int>> nums;
    for (int n = 1; n < SIZE; ++n) nums.emplace_back(sumDiv[n], n);
    sort(nums.begin(), nums.end(), greater<pair<ll, int>>());

    vector<int> ans(t);
    int ptr = 0;
    for (int i = t - 1; i >= 0; --i) {
        int v = qr[i].v, l = qr[i].l, r = qr[i].r, id = qr[i].idx;
        while (ptr < (int)nums.size() && nums[ptr].first > v) {
            update(nums[ptr].second, 1);
            ++ptr;
        }
        ans[id] = find(r) - find(l - 1);
    }

    for (int x : ans) cout << x << '\n';
    return 0;
}