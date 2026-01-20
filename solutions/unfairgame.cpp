#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        while(k > 0 && n != 1) {
            n >>= 1;
            --k;
        }
        if (n == 1 && k > 0) {
            cout << 0 << '\n';
        } else if (n == 0 && k == 0) {
            cout << 0 << '\n';
        } else {
            cout << n << '\n';
        }
    }
}