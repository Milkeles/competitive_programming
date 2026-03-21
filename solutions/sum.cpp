#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll A, B, P, Q;
    cin >> A >> B >> P >> Q;

    ll L = lcm(P, Q);
    ll start = (A + L - 1) / L, end = B / L;
    if (start > end) {
        cout << 0;
    } else {
        cout << L * ((end - start + 1)*(start + end) >> 1);
    }

    return 0;
}