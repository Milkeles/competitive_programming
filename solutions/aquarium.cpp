// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int w = 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(3);

    double b, h, f, a, l;
    cin >> b >> h >> f >> a >> l;
    double tt  = (1.0 * b * h * w) / a;
    double left  = (1.0 * (100 - b) * h * w) / a;
    double right  = (1.0 * 100 * (50 - h) * w) / a;

    bool isLeft = (f < b);
    if (!isLeft) swap(tt, left); 

    while (l--) {
        int p, t;
        cin >> p >> t;

        double ht;
        if (t >= tt + left + right) {
            ht = 50.0;
        } else if (t >= tt + left) {
            ht = h + (t - tt - left) * a / (100.0 * w);
            ht = min(ht, 50.0);
        } else if (t >= tt) {
            bool onLeft = (isLeft ? (p < b) : (p > b));
            if (onLeft) ht = h;
            else ht = (t - tt) * a / ((100.0 - b) * w);
        } else {
            bool onLeft = (isLeft ? (p < b) : (p > b));
            if (onLeft) ht = t * a / (b * w);
            else ht = 0.0;
        }

        cout << ht << '\n';
    }
}