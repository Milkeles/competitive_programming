// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    while(t--) {
        int n, h, l, res = 0, cnt1 = 0, cnt2 = 0;
        cin >> n >> h >> l;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (num <= h && num <= l) ++res;
            else if (num <= h) ++cnt1;
            else if (num <= l) ++cnt2;
        }
        
        int temp = min(cnt1 + cnt2 - (min(cnt1, cnt2) << 1), res);
        res -= temp;
        res = temp + (res >> 1);
        cout << res << '\n';
    }
}