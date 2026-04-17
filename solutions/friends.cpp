#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool notPrime[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i * i <= n; ++i) {
        if(notPrime[i]) continue;
        for(int j = i * i; j <= n; j+=i) notPrime[j] = true;
    }

    ll lcm = 1;
    for (int p = 2; p <= n; ++p) {
        if (notPrime[p]) continue;
        ll pow = p;
        while(pow * p <= n) pow *= p;
        lcm *= pow; 
    }

    cout << lcm;
}