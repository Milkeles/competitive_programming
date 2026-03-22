#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll __int128

using namespace std;

void print128(ll x) {
    if (x > 9) print128(x / 10);
    cout << (char)('0' + x % 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    ll lcmVal = 1;
    for (int i = 2; i <= n; ++i) lcmVal = lcm(lcmVal, (ll)i);

    ll sum = 0;
    for (int i = 1; i <= n; ++i) sum += lcmVal / i;

    ll rem = sum % lcmVal;
    ll g = gcd(rem, lcmVal);
    
    print128(sum / lcmVal); cout << ' ';
    print128(rem / g);      cout << ' ';
    print128(lcmVal / g);
}