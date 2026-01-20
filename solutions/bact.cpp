#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int a, b, c, d;
    ll k;
    cin >> a >> b >> c >> d >> k;
    while(k--){
        a = max(0, min(a * b - c, d));
        if (a == 0 || a == d || a* (b - 1) == c) break;
    }

    cout << a;
    return 0;
}