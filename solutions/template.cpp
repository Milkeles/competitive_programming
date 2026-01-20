// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;

    while(n--) {
        int x, y, z;
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }

    cout << ((a || b || c) ? "NO" : "YES");
    return 0;
}