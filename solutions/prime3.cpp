// Национална олимпиада - Национален кръг > D > 2024
// Author: H. Hristov
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bitset<1000001> notPrime;
short divCnt[1000001];
int prefix[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    for(ll i = 2; i <= 1000000; ++i) {
        if (notPrime[i]) continue;
        for (ll j = i; j <= 1000000; j += i) {
            notPrime.set(j);
            divCnt[j]++;
        }
    }
    for (int i = 1; i < 1000001; ++i) {
        prefix[i] = prefix[i-1];
        if (divCnt[i] == 3) prefix[i]++;
    }
    
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
        // for(a; a <= b; ++a) {
        //     if (divCnt[a] == 3) {
        //         cout << a << " \n"[a==b];
        //     }
        // }
    }
}