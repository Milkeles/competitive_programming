//Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int & x : a) cin >> x;
    for(int & x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0;
    int r = m - 1;
    int cnt = 0;

    for (int i = 0; i < n && l < r; ++i) {
        l = 0;
        r = m - 1;
        start:
            while(l < r && b[l] > a[i]) ++l;
            while(l < r && b[r] < a[i]) --r;
            int cur = min(a[i], min(b[l], b[r]));
            b[l] -= cur;
            a[i] -= cur;
            b[r] -= cur;
            cnt += cur;
        goto start;
    }

    cout << cnt;
}