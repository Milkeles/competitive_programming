// Author: H. Hristov
// Idk if it'd work, all correct solutions use dp? Tough one.

#pragma GCC optimize("O3,unroll-loops,avx2,Ofast")

#define ll long long;

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int NMAX = 2000; 

long long modpow(long long a, long long e = MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long fact[NMAX+1], invfact[NMAX+1];

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= NMAX; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[NMAX] = modpow(fact[NMAX]);

    for (int i = NMAX; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;

    int T;
    cin >> T;
    while (T--) {
        int n, a;
        cin >> n >> a;
        // result = C(2n, n) - C(2n, n-a-1)  (mod MOD)
        long long ans = comb(2*n, n) - comb(2*n, n - a - 1);
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }

    return 0;
}
