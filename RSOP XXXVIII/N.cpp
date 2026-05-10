// RSOP XXXVIII > N
// Author: Retarded piece of shit
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    while(cin >> a >> b) {
        int sum = 0;
        FOR(i, a, b) sum += log10(i) + 1;
        cout << sum;
    }
}