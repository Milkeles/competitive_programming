// RSOP XXXVIII > L
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        vector<char> a;
        for (char c : line) if (c != ' ') a.push_back(c);
        sort(a.begin(), a.end());
        int n = a.size();

        ll k;
        cin >> k;
        cin.ignore();

        if (k == 1) { cout << '\n'; continue; }

        // n ^ (l / 2);
        // rem-th pal of len l
        ll rem = k, l = 1, cnt = n, pr = 1;

        while (rem > cnt) {
            rem -= cnt;
            l++;
            int h = (l + 1) / 2;
            if (h != pr) {
                cnt *= n;
                pr = h;
            }
        }

        // h digits, base x
        ll h = ((l + 1) >> 1), x = rem - 1;
        string res1(h, a[0]);
        for (ll i = h - 1; i >= 0; --i) {
            res1[i] = a[x % n];
            x /= n;
        }
        
        string res2 = res1;
        ll s2 = (l % 2 == 0) ? h - 1 : h - 2;
        for (int i = s2; i >= 0; --i) res2 += res1[i];
        cout << res2 << '\n';
    }
}