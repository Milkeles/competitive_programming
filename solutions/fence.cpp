#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        short xmin = SHRT_MAX, xmax = SHRT_MIN, ymin = SHRT_MAX, ymax = SHRT_MIN;
        while(n--) {
            short x, y;
            cin >> x >> y;
            if (x < xmin) xmin = x;
            if (x > xmax) xmax = x;
            if (y < ymin) ymin = y;
            if (y > ymax) ymax = y;
        }

        
        int side = max(xmax - xmin + 2, ymax - ymin + 2);
        cout << side * 4 << '\n';
    }
    return 0;
}