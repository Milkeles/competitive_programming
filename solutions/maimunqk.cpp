#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
#define ll long long

const ll MOD = 1e8 + 7;
using namespace std;

vector<int> KMP(const string & s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    return pi;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, a, b; string s;
    cin >> n >> a >> b >> s;
    vector<int> pi = KMP(s);

    ll p0num = a, p0den = b, p1num = (b - a), p1den = b;
    vector<ll> dp1(n + 1, 0), dp2(n + 1, 1);

    for (int i = n - 1; i >= 0; --i) {
        int next0 = i, next1 = i;

        //0
        while(next0 > 0 && s[next0] != '0') next0 = pi[next0 - 1];
        if (s[next0] == '0') ++next0;

        //1
        while(next1 > 0 && s[next1] != '1') next1 = pi[next1 - 1];
        if(s[next1] == '1') ++next1;

        ll comn = (p0den * p1den);
        ll num = comn;
        num = (num + (p0num * p1den % MOD)) % MOD;
        num = (num + (p1num * p0den % MOD)) % MOD;
        dp1[i] = num;
        dp2[i] = comn;
    }
    auto modPow = [](ll a, ll b, ll mod) {
        ll res = 1;
        a %= mod;
        while(b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    };
    auto modInv = [&](ll a) { return modPow(a, MOD - 2, MOD); };

    ll res = (dp1[0] * modInv(dp2[0])) % MOD;
    cout << res;
    return 0;
}
