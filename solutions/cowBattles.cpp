//Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int rounds = n;
        n = (1 << n);
        
        vector<int> a(n);
        for (int & num : a) cin >> num;
        
        vector<int> xr(2 * n);
        vector<int> w(2 * n);
        
        for (int i = 0; i < n; i++) {
            xr[n + i] = a[i];
            w[n + i] = 0;
        }
        
        for (int i = n - 1; i >= 1; i--) {
            int lx = xr[i << 1];
            int rx = xr[i << 1 | 1];
            xr[i] = lx ^ rx;
            w[i] = (lx >= rx ? 0 : 1);
        }
        
        while (q--) {
            int b, c;
            cin >> b >> c;
            --b;
            
            int old = a[b];
            
            int idx = n + b;
            xr[idx] = c;
            for (idx >>= 1; idx >= 1; idx >>= 1) {
                int lx = xr[idx << 1];
                int rx = xr[idx << 1 | 1];
                xr[idx] = lx ^ rx;
                w[idx] = (lx >= rx ? 0 : 1);
            }
            
            long long pos = 0;
            long long sz = 1;
            idx = n + b;
            
            while (idx > 1) {
                int side = idx & 1;
                int par = idx >> 1;
                if (w[par] == side) pos += sz;
                idx = par;
                sz <<= 1;
            }
            
            cout << n - 1 - pos << '\n';
            
            idx = n + b;
            xr[idx] = old;
            for (idx >>= 1; idx >= 1; idx >>= 1) {
                int lx = xr[idx << 1];
                int rx = xr[idx << 1 | 1];
                xr[idx] = lx ^ rx;
                w[idx] = (lx >= rx ? 0 : 1);
            }
        }
    }
    return 0;
}