// Author: H. Hristov
// Just combinatorics, sum of combinations. Same idea as FMI 3 and passes my tests, should be correct.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    map<string,ll> cnt;

    auto calc = [&]() {
        ll ans = 0;
        for (auto &kv : cnt) {
            ll c = kv.second;
            if (c >= 3)
                ans += c * (c - 1) * (c - 2) / 6;
        }
        cout << ans << "\n";
        cnt.clear();
    };

    while (getline(cin, line)) {
        if (line == "June14") {
            calc();
        } else {
            cnt[line.substr(0,5)]++;
        }
    }
    
    if (!cnt.empty()) calc();

    return 0;
}
