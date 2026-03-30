// Национална олимпиада - Национален кръг > C > 2015 > segments
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll floorDiv(ll a, ll b) {
    ll q = a / b;
    if ((a ^ b) < 0 && a % b != 0) q--; 
    return q;
}

ll ceilDiv(ll a, ll b) {
    ll q = a / b;
    if ((a ^ b) > 0 && a % b != 0) q++; 
    return q;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a, b, c, d; char i1, i2;
    map<ll, ll> diff;
    while(n--) {
        cin >> i1 >> a >> b >> c >> d >> i2;
        ll l  = (i1 == '[') ? ceilDiv(a, b)  : floorDiv(a, b) + 1;
        ll r = (i2 == ']') ? floorDiv(c, d) : ceilDiv(c, d) - 1;

        if(l <= r) {
            diff[l]++;
            diff[r + 1]--;
        }
    }

    ll res = 0, curr = 0, prev = 0;
    bool first = true;

    for (auto [p, val] : diff) {
        if (!first && curr > 0)
            res += p - prev;
        curr += val;
        prev = p;
        first = false;
    }
    if(curr > 0) ++res;
    cout << res;
}

/*
Autism Notes:
1. Use floorDiv/ceilDiv instead of regular division when computing integer
   boundaries from fractions, especially with negative numbers.

2. For open brackets, do NOT adjust after applying ceil/floor:
   - '[' → ceilDiv(a,b)       smallest integer >= a/b
   - '(' → floorDiv(a,b) + 1  smallest integer >  a/b
   - ']' → floorDiv(c,d)      largest  integer <= c/d
   - ')' → ceilDiv(c,d)  - 1  largest  integer <  c/d
   The key insight: when a/b is non-integer, ceil already jumps past it,
   so a naive +1 after ceilDiv would overshoot by 1.

3. Difference array: diff[l]++, diff[r+1]-- marks the range [l, r].
   Sweeping and summing gives the coverage count at each integer point.
   res += p - prev counts the length of each covered segment.
   The +1 shift on r ensures singular points (where l == r) have a
   nonzero-width entry and are counted correctly.

4. After the sweep line loop, check if(curr > 0) to flush the last segment.
   The loop only accounts for a segment when it sees the *next* boundary,
   so if the final diff entry is an opening with no explicit close after it,
   that segment is never flushed inside the loop. In this problem it cannot
   happen since every interval is closed by diff[r+1]--, but in general
   sweep line problems this guard is essential.
*/