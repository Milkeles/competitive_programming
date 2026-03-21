#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, divSum = 1;
    cin >> n;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divSum += i;
            ll d = n / i;

            if (d != i) divSum += d;
        }
    }

    cout << divSum << '\n' << (divSum > n ? "YES" : "NO");
}