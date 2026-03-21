#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        ll minSum = k * (k + 1) / 2;
        ll ans = -1;

        for (ll d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                ll d1 = d;
                ll d2 = n / d;

                if (n / d1 >= minSum)
                    ans = max(ans, d1);

                if (n / d2 >= minSum)
                    ans = max(ans, d2);
            }
        }

        cout << ans << '\n';
    }
}