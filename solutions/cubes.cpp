// Author: H. Hristov
#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ull n;
    cin >> n;
    auto cube = [](ull x) {
        return x * x * x;
    };

    int cnt = 0;

    while(n > 1) {
        ull s = cbrt(n);
        if (cube(s + 1) <= n) ++s;
        else if (cube(s) > n) --s;
        n -= cube(s);
        ++cnt;
    }
    if (n >= 1) cnt += n;

    cout << cnt;
    return 0;
}