// Национална олимпиада - Национален кръг > D > 2025 > primes
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bool notPrime[26001];
short cntPrimes[26001];
short pref[26001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    notPrime[0] = notPrime[1] = true;

    for(int i = 2; i <= 26000; ++i) {
        if (notPrime[i]) {
            cntPrimes[i] = cntPrimes[i - 1];
        } else {
            cntPrimes[i] = cntPrimes[i - 1] + 1;

            for (int j = i * i; j <= 26000; j += i)
                notPrime[j] = true;
        }
        pref[i] = pref[i - 1] + (!notPrime[cntPrimes[i]]);
    }

    short t, l, r;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}