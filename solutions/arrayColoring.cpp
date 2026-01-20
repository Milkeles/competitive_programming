// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<short, short> a, pair<short, short> b) {
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    while(t--) {
        short n;
        bool valid = true;
        cin >> n;
        vector<short> a(n);
        for(short & num : a) cin >> num;
        for(int i = 0; i < n - 1; ++i) {
            if ((a[i]&1) == (a[i+1]&1)) {
                valid = false;
                break;
            } 
        }

        cout << (valid ? "YES\n" : "NO\n");
    }
}