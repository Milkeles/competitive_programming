#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int16_t> a(n);
    int s1 = 0, s2 = 0;
    for (int16_t & x : a) {
        cin >> x;
        s1 += x;
    }
    s1 -= a[0];
    
    for(int i = 0; i < n-1; ++i) {
        s1 -= a[i + 1];
        s2 += a[i];
        if (s1 == s2) {
            cout << i + 2;
            return 0;
        }
    }

    cout << 0;
}