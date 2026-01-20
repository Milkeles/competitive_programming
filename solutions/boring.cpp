#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math")
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, sum = 0;
    cin >> n >> k;

    int kDigit = to_string(k)[0] - '0';

    for (int i = 1; i < kDigit; ++i) {
        ll cur = i;
        while(cur <= n) {
            ++sum;
            cur = cur * 10 + i;
        }
    }

    ll cur = kDigit;
    while(cur <= k) {
        ++sum;
        if (cur == k) break;
        cur = cur * 10 + kDigit;
    }

    cout << sum;

    return 0;
}