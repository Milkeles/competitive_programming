// Национална олимпиада - Национален кръг > D > 2010 > machine
// Author: H. Hrtistov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt1[10] = {0}, cnt2[10] = {0};
    string s, dig;
    cin >> s;
    for (char & c : s)
        if (c >= '0' && c <= '9')
            cnt1[c - '0']++, cnt2[c - '0']++;
    
    ll mx = 0, mn = 0;
    for (int d = 9; d >= 0; d--)
        while (cnt1[d]--)
            mx = mx * 10 + d;
    
    for (int d = 1; d <= 9; d++) {
        if (cnt2[d] == 0) continue;
        mn = d;
        cnt2[d]--;
        break;
    }

    for (int d = 0; d <= 9; d++)
        while (cnt2[d]--)
            mn = mn * 10 + d;
    
    ll pos = (mx - mn) % 3015;

    if (pos < 2010)
        cout << 2010 + pos;
    else
        cout << 1005 + (pos - 2010);

    return 0;
}