
#define ll long long
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> prefix(d + 1);
    prefix[1] = 1;
    for(int i = 2; i <= d; ++i) {
        prefix[i] = prefix[i - 1] + i;
    }

    ll start = b - a, res = 0;
    for (start; start > 0; --start) {
        res += (start * start);
        if (c - start + 1 < b) {
            // cout << prefix[b - (c - start + 1)] << '\n';
            res -= prefix[b - (c - start + 1)];
        }
    }

    cout << res;
    return 0;
}
