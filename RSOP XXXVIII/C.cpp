// RSOP XXXVIII > C, LIS
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back
using ll = long long;
using ull = unsigned long long;

using namespace std;

// V1 -> dp, O(n ^ 2) => TL, V2:
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        FOR(i, 1, n) {
            int x;
            cin >> x;
            int lo = 0, hi = a.size();
            while (lo < hi) {
                int mid = ((lo + hi) >> 1);
                if (a[mid] < x) lo = mid + 1;
                else hi = mid;
            }
            if (lo == (int)a.size()) a.pb(x);
            else a[lo] = x;
        }
        cout << a.size() << '\n';
    }
}