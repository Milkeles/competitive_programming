// Author: H. Hristov
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d;
    cin >> n >> d;
    int B = d * 2;

    vector<string> nums(n);
    for (string& x : nums) cin >> x;

    ll lcmVal, num;
    cin >> lcmVal;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        lcmVal = lcm(lcmVal, num);
    }

    int bestStart = -1, bestEnd = -1, curStart = 0, bestLen = 0;

    for (int i = 0; i < n; i++) {
        ll r = 0;
        for (char c : nums[i]) {
            int dv = (c >= '0' && c <= '9') ? c - '0' : (c >= 'A' && c <= 'Z') ? 10 + (c - 'A') : 36 + (c - 'a');
            r = (B * r + dv) % lcmVal;
        }

        if (r == 0) {
            if (i - curStart + 1 > bestLen) {
                bestLen = i - curStart + 1;
                bestStart = curStart;
                bestEnd = i;
            }
        } else {
            curStart = i + 1;
        }
    }

    if (bestLen == 0)
        cout << -1;
    else
        cout << bestStart + 1 << ' ' << bestEnd + 1;

    return 0;
}