// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    short t;
    cin >> t;
    while(t--) {
        int n, res = -1, cnt = 0;
        string a;
        cin >> n >> a;

        for(int i = n-1; i >= 0; --i) {
            char c = a[i];
            if (c == '(') ++cnt;
            else {
                if (cnt >= 2) {
                    res = n - 2;
                    break;
                }
            }
        }

        cout << res << '\n';
    }

}