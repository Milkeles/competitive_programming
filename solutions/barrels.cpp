#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    vector<int> a(n);
    for (int & num : a) cin >> num;

    auto floorDiv = [](int & a, int & b) {
        return (a / b - ((a ^ b) < 0 && a % b != 0));
    };

    sort(a.begin(), a.end(), greater<>());
    int res = s / a[0];
    int t = res * a[0], firstMin = res;
    int i = 1, p = s - t;
    while(p > 0 && i < n) {
        if (a[i] <= p) {
            int q = p / a[i];
            p -= q * a[i];
            firstMin += q;
        }
        ++i;
    }

    int curMin, bestMin = firstMin;
    while(true) {
        // Problem. We can't remove a[0] every time.
        // Sometimes, the optimal solution would require removing any of the previously added size.
        t -= a[0]; --res; curMin = res;
        i = 1; p = s - t;
        while(p > 0 && i < n) {
            if (a[i] <= p) {
                int q = p / a[i];
                p -= q * a[i];
                curMin += q;
            }
            ++i;
        }
        if (curMin <= bestMin) bestMin = curMin;
        else break;
    }

    cout << bestMin;
}