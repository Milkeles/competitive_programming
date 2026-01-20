//Author: H. Hristov
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

/*int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int &num : a) cin >> num;

    vector<vector<pair<int, ll>>> prefix(n);
    for (int i = 0; i < n; ++i) {
        int current_min = a[i];
        ll sum = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] < current_min) current_min = a[j];
            sum += current_min;
            prefix[i].emplace_back(current_min, sum);
        }
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += prefix[i].back().second;
    }

    cin >> q;
    while (q--) {
        int l, v;
        cin >> l >> v;
        ll oldRes = res;

        for (int i = 0; i < l; ++i) {
            auto &[curMin, sum] = prefix[i][l - i];
            if (v < curMin) {
                res += sum - (curMin - v);  
            } else {
                res += sum;
            }
            res = res % MOD;
        }
        res += v;
        res = res % MOD;
        a[l] = v;
    }

    cout << res % MOD;

    return 0;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    cin >> q;
    
    vector<vector<pair<int, int>>> prefix(n + 1);
    for (int i = 0; i < q; ++i) {
        int ind, val;
        cin >> ind >> val;
        prefix[ind + 1].push_back({val, i});
    }
    
    vector<pair<int, ll>> stack;
    stack.push_back({0, 0});
    
    ll total = 0;
    ll curSum = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (auto [val, qid] : prefix[i]) {
            int l = 0, r = stack.size();
            while (l < r - 1) {
                int mid = (l + r) / 2;
                if (a[stack[mid].first] < val) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            
            ll query_contribution = (curSum + stack[l].second + 
                                    (ll)(i - stack[l].first) * val) % MOD;
            total = (total + query_contribution) % MOD;
        }

        while (!stack.empty() && a[stack.back().first] >= a[i]) {
            stack.pop_back();
        }
        
        auto [pind, psum] = stack.back();
        
        ll sum = (psum + (ll)(i - pind) * a[i]) % MOD;
        stack.push_back({i, sum});
        
        curSum = (curSum + sum) % MOD;
    }
    
    total = (total + curSum) % MOD;
    
    cout << total;
    
    return 0;
}