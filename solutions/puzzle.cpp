#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short m, n;
    cin >> m >> n;
    bool gvalid = true;
    vector<int> firsts;
    while(m--) {
        int cur, last, commonDif;
        bool valid = true;
        cin >> last;
        firsts.push_back(last);
        cin >> cur;
        commonDif = abs(cur - last);
        for(int i = 2; i < n; ++i) {
            last = cur;
            cin >> cur;
            if (abs(cur-last) != commonDif && valid) {
                commonDif = abs(cur - last);
                valid = false;
            } else {
                gvalid = false;
            }
        }
    }

    if (gvalid) {
        int largest = INT_MIN, res = 0, cur;
        for(int & x : firsts) {
            cur = n - x - 1;
            if (largest < cur) largest = cur;
            res += cur;
        }
        cout << res - largest;
    } else {
        cout << -1;
    }
}