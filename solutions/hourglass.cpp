#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    while(t--) {
        int s, k, m, q;
        cin >> s >> k >> m;
        if (s > k) {// seems mostly right, idk what isn't right...
            // determine on which side is the hourglass flipped, k or s - k, and how much time remains in it after he leaves.
            q = m / k;
            if (q & 1) cout << k - m % k;
            else cout << s - m % k;
        } else if (s <= k) { // correct, completely.
            // determine if he leaves before or after the hourglass runs out of time.
            q = m % k;
            if (q > s) cout << 0;
            else cout << s - q;
        }

        cout << '\n';
    }
}