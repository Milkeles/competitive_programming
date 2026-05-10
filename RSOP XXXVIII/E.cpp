// RSOP XXXVIII > E
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592653589793238462643383279

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        cout << ceil((l * l) / (4 * n * tan(PI/n))) << '\n';
    }
}