// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bitset<1'000'001> dp;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, t, last = 0;
    cin >> a >> b >> t;

    while(t--) {
        string n;
        cin >> n;
        int r = 0;
        for (char & c : n)
            r = (10LL * r + (c - '0')) % (a + b);

        cout << (r >= a ? '1' : '2') << '\n';
    }
}