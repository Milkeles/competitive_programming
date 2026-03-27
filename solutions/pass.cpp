// Национална олимпиада - Национален кръг > D > 2025 > pass
// Author: H. Hristov
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n, ans;
    cin >> n;

    sort(n.begin(), n.end());

    if (n.size() % 2 == 1) {
        int limit = n.size() / 2 + 1;
        int cnt = 0;
        for (char c : n) {
            if (cnt++ == limit) break;
            ans.push_back(c);
        }
    } else {
        int i = 0;
        while (i < (int)n.size()) {
            ans.push_back(n[i + 1]);
            if (n[i] != n[i + 1]) break;
            i += 2;
        }
        for (auto it = n.begin() + i + 2; ans.size() < n.size() / 2; ++it) {
            ans.push_back(*it);
        }
    }

    cout << ans << "\n";
    return 0;
}