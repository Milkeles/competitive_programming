// H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#include <bits/stdc++.h>

using namespace std;

ll pow(ll x, ll n) {
    if (n == 0) return 1;
    ll u = pow(x, (n >> 1));
    u = u * u;
    if(n & 1) u *= x;

    return u;
}

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1;
    ll u = modpow(x, (n >> 1), m);
    u = (u * u) % m;
    if (n & 1) u = (u * x) % m;
    return u;
}

const ll MOD = 1e8 + 7;
int main() {
    cout << (1 << 2 | 1);
    return 0;
}