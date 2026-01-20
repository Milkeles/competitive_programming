// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 3; ++i) {
        ll num, prod = 1;
        cin >> num;
        for (ll i = 1; i <= num % 20; i += 2) {
            if (i % 5 == 0) continue;
            prod = (prod * (i % 10)) % 10;
        }
        cout << prod << '\n';
    }
}